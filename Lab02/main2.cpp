#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int procStatus; // variable that holds information about the termination status of a child process.

int subtract(int arg1, int arg2); //Subtraction function prototype

int add(int arg1, int arg2); // Addition function prototype

int mult(int arg1, int arg2); // Multiplication function prototype

int main(int argc, char * argv[]) {

    int val1, val2, result; // Creating varibles
    val1 = 10;
    val2 = 5;
    printf("Value 1: %d\nValue 2: %d\n", val1, val2); //printing to terminal val1 and val2 that way the user can see what numbers are being manipulated
    printf("Parent PID: %d\n", getpid()); //Print parent ID

    pid_t cpid; //Child process ID
    cpid = fork(); //Fork for child1

    if (cpid == 0){ //If child
        result = subtract(val1, val2); //Invoke Subtraction function
        printf("Child1 PID: %d, Subtract Result = %d\n", getpid(), result); //Print results

        pid_t c2pid; //Child2 Process ID
        c2pid = fork(); //Fork for child 2
        if (c2pid == 0){ //if child 2
            result = add(val1, val2); //Invoke add function
            printf("Child2 PID: %d, Add Result = %d\n", getpid(), result); //print child 2 results
            exit(0); //terminate the 2nd child
        }else{
            wait(&procStatus); //wait for child 2 to terminate
            result = mult(val1, val2); //invoke multiplication function
            printf("Child1 PID: %d, Multiply Result = %d\n", getpid(), result); //print results
            exit(0); //Terminate the first child
        }
        
    }else{
        wait(&procStatus); //wait for child 1 to terminate
        cout << "Done" << endl; // print done
    }
    return 0; //return

}

int subtract(int arg1, int arg2){ //simple sub function
    int result;
    result = arg1 - arg2;
    return result;
}

int add(int arg1, int arg2){ // simple add func
    int result;
    result = arg1 + arg2;
    return result;
}

int mult(int arg1, int arg2){ //simple multipy func
    int result;
    result = arg1 * arg2;
    return result;
}