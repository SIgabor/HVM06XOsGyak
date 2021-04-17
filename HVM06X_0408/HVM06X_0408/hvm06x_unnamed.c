#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>



int main()
{
    int a[2];
    char str[] = "Slyizs Istvan Gabor HVM06X";
    pid_t p;
    p = fork();

    if(p < 0){
        fprintf(stderr, "fork failed");
        return 1;
    }
    else if(p > 0){

        close(a[1]);
        read(a[0], str, strlen(str));
        printf("%s", str);
        close(a[0]);
    }
    else{
        write(a[1], str, strlen(str));
        close(a[1]);
        exit(0);
    }

    return 0;
}

