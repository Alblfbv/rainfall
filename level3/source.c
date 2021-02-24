#include <stdio.h>
#include <stdlib.h>

void v(){
    unsigned int eax;
    char buff[536];

    fgets(buff, 512, stdin);
    printf(buff);
    if (eax == 40){
        fwrite("Wait what?!\n", 1, 12, stdout);
        system("/bin/sh");
    }
    return;
}

int main(){
    v();
    return(0);
}