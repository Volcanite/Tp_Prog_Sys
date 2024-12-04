//
// Created by matis on 04/12/24.
//

#include "Q2.h"

void Q2() {

    char input[MaxSize];
    my_write(PromptQ2_1);
    my_read(input);

    if (strcmp(input, "fortune") == 0) {
        int status;
        pid_t pid = fork(); // Create a child process
        if (pid > 0) {
            // In the parent process: wait for the child to finish
            wait(&status);
        }
        else if (pid == 0) {
            // In the child process: execute the "fortune" command
            execlp("fortune", "fortune", NULL); // No need for "-o", assuming the system has it installed
            // If execlp fails, terminate the child process
            _exit(1);
        }

        time_t now = time(NULL);
        struct tm *local = localtime(&now);
        char date[MaxSize];
        strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y\n", local);
        my_write(date);
        my_write("PromptQ2_1\n");

    }
}
