//
// Created by matis on 04/12/24.
//

#include "Q3.h"
#include "my_write.h"
#include "my_read.h"

#define PromptQ3_1 "enseash % "
#define Prompt_Exit "exit\n"
#define Prompt_Bye "Bye Bye\n"
#define Prompt_Dollars "$\n"
#define Equal 0

void Q3() {

    char input[MaxSize];

    my_write(PromptQ3_1);
    my_read(input);

    if (strcmp(input, Prompt_Exit ) == Equal) {
       my_write(Prompt_Bye);
       my_write(Prompt_Dollars);
       exit(1);
       }
}