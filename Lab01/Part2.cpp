#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 1;
    while(i <= 10){
        pid_t pid = fork(); // Creates child
        if (pid == 0) {
            // If a child process
            printf("I am child %d with PID: %d\n", i, getpid()); //print info
            exit(0); // kill the child
        }
        sleep(1); //slight delay to make sure it prints correctly
        i++; // increment i
    }
    return 0;
}
