// system_info.cpp
// Single-file system info tool for Windows & Linux
// Compile: Linux: g++ system_info.cpp -o system_info
//          Windows: g++ system_info.cpp -o system_info -lws2_32

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <intrin.h>
#include <tchar.h>
#include <vector>
#else
#include <sys/utsname.h>
#include <unistd.h>
#include <fstream>
#endif

using namespace std;

void printSystemInfo() {
#ifdef _WIN32
    // OS Version
    OSVERSIONINFOEX osvi = { sizeof(OSVERSIONINFOEX) };
    GetVersionEx((OSVERSIONINFO*)&osvi);
    cout << "OS: Windows " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion 
         << " Build " << osvi.dwBuildNumber << endl;

    // CPU Info
    int cpuInfo[4] = {-1};
    __cpuid(cpuInfo, 0);
    char vendor[0x20];
    memset(vendor, 0, sizeof(vendor));
    *reinterpret_cast<int*>(vendor) = cpuInfo[1];
    *(reinterpret_cast<int*>(vendor)+1) = cpuInfo[3];
    *(reinterpret_cast<int*>(vendor)+2) = cpuInfo[2];
    cout << "CPU Vendor: " << vendor << endl;

    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);
    cout << "Number of Cores: " << siSysInfo.dwNumberOfProcessors << endl;

    // RAM Info
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    cout << "Total RAM: " << statex.ullTotalPhys / (1024*1024) << " MB\n";

#else
    // OS Info
    struct utsname buffer;
    uname(&buffer);
    cout << "OS: " << buffer.sysname << " " << buffer.release << " " << buffer.version << endl;
    cout << "Machine: " << buffer.machine << endl;

    // CPU Info
    ifstream cpuinfo("/proc/cpuinfo");
    string line;
    while(getline(cpuinfo, line)){
        if(line.find("model name")!=string::npos){
            cout << line << endl;
            break;
        }
    }

    // Number of cores
    long ncores = sysconf(_SC_NPROCESSORS_ONLN);
    cout << "Number of Cores: " << ncores << endl;

    // RAM Info
    ifstream meminfo("/proc/meminfo");
    while(getline(meminfo, line)){
        if(line.find("MemTotal")!=string::npos){
            cout << line << endl;
            break;
        }
    }

    // Hostname
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    cout << "Hostname: " << hostname << endl;
#endif
}

int main() {
    cout << "=== System Information ===\n";
    printSystemInfo();
    return 0;
}
