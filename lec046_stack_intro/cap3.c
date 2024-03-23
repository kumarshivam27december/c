#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <windows.h>

int main() {
    pid_t p1, p2, p3;
    
    p1 = getpid(); // Get parent process ID
    
    printf("Parent Process ID: %d\n", p1);
    printf("Creating child processes...\n");
    
    p2 = fork(); // Create first child process
    
    if (p2 == -1) {
        printf("Error creating child process P2\n");
        exit(1);
    }
    else if (p2 == 0) {
        // Child Process P2
        printf("In Child Process P2\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
        exit(0);
    }
    else {
        // Parent Process
        wait(NULL); // Wait for child process to finish
        
        p3 = fork(); // Create second child process
        
        if (p3 == -1) {
            printf("Error creating child process P3\n");
            exit(1);
        }
        else if (p3 == 0) {
            // Child Process P3
            printf("In Child Process P3\n");
            printf("Process ID: %d\n", getpid());
            printf("Parent Process ID: %d\n", getppid());
            sleep(2); // Sleep for 2 seconds to make P3 a zombie
            printf("Zombie Process P3\n");
            exit(0);
        }
        else {
            // Parent Process
            wait(NULL); // Wait for child process to finish
        }
    }

    return 0;
}
