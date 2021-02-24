#include <stdio.h>
#include <stdlib.h>

int main(){
    char buff[80];

    gets(buff);
    return(0);
}
void run(){
    fwrite("Good... Wait what?\n", 1, 19, stdout);
    system("/bin/sh");
    return;
}