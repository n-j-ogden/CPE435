#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {

    int i = 1;
    int n;

    cout << "Please enter an EVEN number to create that number of processes: ";
    cin >> n;

    while (n%2 != 0){
        cout << "Error! That number is not even! WE TERMINATE!" << endl;
        return 0;
    }

    while(i <= n){
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
