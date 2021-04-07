#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void do_nothing();
void handleSignals(int sig);

int main() {

    signal(SIGINT, handleSignals);
    signal(SIGQUIT, handleSignals);
    unsigned sec=1;

    while (1) {
        alarm(sec);
        signal(SIGALRM, do_nothing);
        printf("varok de meddig?\n");
        pause();
    }

    return 0;
}

void do_nothing(){ ;}

void handleSignals(int sig) {
    if (sig == SIGQUIT) {
        write(STDOUT_FILENO, "SIGQUIT lett megadva  -  ", 25);
    }

    else if (sig == SIGINT) {
        write(STDOUT_FILENO, "SIGINT lett megadva  -  ", 24);
        signal(SIGINT, SIG_DFL);
    }
}
