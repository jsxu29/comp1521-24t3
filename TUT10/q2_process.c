/*
This program prints the following information:
    The current date.
    The current time.
    The current user.
    The current hostname.
    The current working directory.

Example:
    ./now
    29-02-2022
    03:59:60
    cs1521
    zappa.orchestra.cse.unsw.EDU.AU
    /home/cs1521/lab08

Useful commands:
    date +%d-%m-%Y
    date +%T
    whoami
    hostname -f
    realpath .
*/

// we create a process that runs command "date +%d-%m-%Y"
// we create a process that runs command "date +%T"
// ... 

// function that creates a process, runs the command given (pass command via arguments), wait for the process to finish executing

// extern - variable is defined elsewhere, in this case, environ is defined by the system environment

#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

// pass in command
void spawn_process_and_wait(char **argv) {

    pid_t pid;
    int status = posix_spawn(&pid, argv[0], NULL, NULL, argv, environ);
    if (status != 0) {
        perror("error in posix_spawn");
        exit(1);
    }

    int waitpid_status;
    if (waitpid(pid, &waitpid_status, 0) == -1) {
        perror("waitpid fialed");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    // we call this function for each command
    /*
    date +%d-%m-%Y
    date +%T
    whoami
    hostname -f
    realpath .
    */

    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_process_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    spawn_process_and_wait(time_argv);

    char *whoami_argv[] = {"/bin/whoami", NULL};
    spawn_process_and_wait(whoami_argv);

    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    spawn_process_and_wait(hostname_argv);

    char *realpath_argv[] = {"/bin/realpath", ".", NULL};
    spawn_process_and_wait(realpath_argv);

    return 0;
}