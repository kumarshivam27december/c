#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main() {
    // Create a music object
    sf::Music music;

    // Load a music file
    if (!music.openFromFile("path_to_your_music_file.ogg")) {
        std::cerr << "Error: Could not load music file!" << std::endl;
        return -1;
    }

    // Play the music
    music.play();

    // Keep the application running while music plays
    std::cout << "Press Enter to stop the music and exit..." << std::endl;
    std::cin.get();

    // Stop the music
    music.stop();

    return 0;
}
