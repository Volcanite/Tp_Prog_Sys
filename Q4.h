//
// Created by matis on 04/12/24.
//

#ifndef Q4_H
#define Q4_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

#define MAXSIZE 1024
#define MSG_EXIT "[exit:%d]\n"
#define MSG_SIGN "[sign:%d]\n"

#include "my_write.h"
#include "my_read.h"
#define PromptQ4_1 "enseash $"
#define Fork_error "Fork error"
#define Fork_error2 "Command not found"

void Q4();
void Show_it(char *text, int val);



#endif //Q4_H
