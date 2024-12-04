//
// Created by matis on 04/12/24.
//
#include "Q5.h"
#include "my_write.h"
#include "my_read.h"

int status2 = 0;
struct timespec start_time;
struct timespec end_time;

void Show_it2(const char *text, int val1, int val2) { // We adapt the function before to add the time
    char buff[MAXSIZE];
    sprintf(buff, text, val1, val2);
    write(STDOUT_FILENO, buff, strlen(buff));
}

void start_timer() {
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

void end_timer() {
    clock_gettime(CLOCK_MONOTONIC, &end_time);
}

int get_time() {
    return (int)((end_time.tv_sec - start_time.tv_sec) * 1000 +
                 (end_time.tv_nsec - start_time.tv_nsec) / 1e6);
}

void Q5(){
    char input[128];
    my_write(PROMPT);
    my_read(input);

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork error");
        exit(1);
    }
    if (pid == 0) {
        execlp(input, input, NULL);
        perror("Command not found");
        exit(1);
    }
    else {
        start_timer();
        wait(&status2);
        end_timer();
        int elapsed_time = get_time();
        if (WIFEXITED(status2)) {
            Show_it2(MSG_EXIT, WEXITSTATUS(status2),elapsed_time);
        }
        else if (WIFSIGNALED(status2)) {
            Show_it2(MSG_SIGN, WTERMSIG(status2), elapsed_time);
        }
    }
}