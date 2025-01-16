#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    int val = 0;
    pid_t cpid;
    cpid = fork();

    if (cpid == 0){
        val += 2;
        printf("Val: %d with Child PID: %d\n", val, getpid());
    }else{
        val += 5;
        printf("Val: %d with Parent PID: %d\n", val, getpid());
    }
    exit(0);
}