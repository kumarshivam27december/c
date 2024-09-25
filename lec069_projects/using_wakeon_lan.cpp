#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void sendMagicPacket(const std::string& macAddress, const std::string& broadcastIP) {
    // Prepare the magic packet
    unsigned char packet[102]; // 6 bytes of sync + 16*6 bytes of MAC
    std::memset(packet, 0xff, 6); // Set first 6 bytes to 0xFF

    // Convert MAC address to binary
    int mac[6];
    if (sscanf(macAddress.c_str(),
               "%x:%x:%x:%x:%x:%x",
               &mac[0], &mac[1], &mac[2],
               &mac[3], &mac[4], &mac[5]) != 6) {
        std::cerr << "Invalid MAC address format." << std::endl;
        return;
    }

    // Fill the rest of the packet with the MAC address
    for (int i = 0; i < 16; ++i) {
        std::memcpy(packet + 6 + i * 6, mac, 6);
    }

    // Create a UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }

    // Allow broadcast
    int broadcastEnable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0) {
        std::cerr << "Failed to set socket options." << std::endl;
        close(sockfd);
        return;
    }

    // Set up the broadcast address
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9); // WoL uses port 9
    addr.sin_addr.s_addr = inet_addr(broadcastIP.c_str());

    // Send the magic packet
    ssize_t sentBytes = sendto(sockfd, packet, sizeof(packet), 0,
                               (struct sockaddr*)&addr, sizeof(addr));
    if (sentBytes < 0) {
        std::cerr << "Failed to send magic packet." << std::endl;
    } else {
        std::cout << "Magic packet sent successfully." << std::endl;
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <MAC Address> <Broadcast IP>" << std::endl;
        return 1;
    }

    std::string macAddress = argv[1];
    std::string broadcastIP = argv[2];

    sendMagicPacket(macAddress, broadcastIP);

    return 0;
}
