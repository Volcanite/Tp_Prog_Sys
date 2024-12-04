//
// Created by matis on 04/12/24.
//
#include "my_write.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void my_write(char* str){
    write(STDOUT_FILENO, str, strlen(str));
  }
