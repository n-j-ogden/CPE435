#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    printf("Parent PID: %d\n", getpid());
    int pid = fork();

    if (pid == 0){
        printf("Child PID: %d\n", getpid());
    }else{
        printf("Parent PID: %d. I will die now.\n", getpid());
        exit(0);
    }
    cout << "Now waiting 5 seconds..." << endl;
    sleep(5);
    printf("I am Child PID: %d. My new parent PID: %d\n", getpid(), getppid());
    return 0;
}