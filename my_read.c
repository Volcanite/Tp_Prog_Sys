//
// Created by matis on 04/12/24.
//
#include "my_read.h"
#include <stdlib.h>
#include <stdio.h>

void my_read(char* input){
  while(1){
      int result = read(STDIN_FILENO, input, MaxSize);
      if (result == -1) {
          perror("Error reading input");
          exit(1);
      }
      if(result >0){
          input[result -1] = '\0';
          break;
      }
  }
}