#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    int pid;
    pid = fork();
    if (pid > 0){
        printf("I am the parent. My PID is: %d. I will sleep now for 50 seconds\n", getpid());
        sleep(50);
    }else{
        printf("I am the child. My PID is %d. My Parents PID is: %d. I will die now.\n", getpid(), getppid());
        exit(0);
    }
    printf("all done!");
    return 0;
}