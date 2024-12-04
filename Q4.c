//
// Created by matis on 04/12/24.
//
#include "Q4.h"

int status = 0;

void Show_it(char *text, int val) {
    char buff[MAXSIZE];
    sprintf(buff, text, val);
    my_write(buff);
}

void Q4(){
    char input[128];
    my_write(PromptQ4_1);
    my_read(input);

    pid_t pid = fork();

    if (pid == -1) {
        perror(Fork_error);
        exit(1);
    }
    else if (pid == 0) {
        execlp(input, input, NULL);
        perror(Fork_error2);
        exit(1);
    }
    else {
        wait(&status);
        if (WIFEXITED(status)) { // Display the exit status or signal information
            Show_it(MSG_EXIT, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
          Show_it(MSG_SIGN, WTERMSIG(status));
    }

  }
}