/*
README

ab@cd-x:$ gcc -g -fno-stack-protector test_overflow.c 
ab@cd-x:$ ./a.out mypass
Access granted
ab@cd-x:$ ./a.out yourpass
Access granted
ab@cd-x:$ ./a.out wepass
Access denied
ab@cd-x:$ ./a.out wepassssssssssssssssss
Access granted

ab@cd-x:$ gcc -g -fstack-protector test_overflow.c 
ab@cd-x:$ ./a.out wepass
Access denied
ab@cd-x:$ ./a.out mypass
Access granted
ab@cd-x:$ ./a.out yourpass
Access granted
ab@cd-x:$ ./a.out wepassssssssssssssssss
*** stack smashing detected ***: ./a.out terminated

Compilation
With bug
gcc -g -fno-stack-protector test_overflow.c 

No bug

gcc -g  test_overflow.c 

*/


#include <stdio.h>
#include <string.h>

int check_password(char *password){
    int flag = 0;
    char buffer[20];
    strcpy(buffer, password);

    if(strcmp(buffer, "mypass") == 0){
        flag = 1;
    }
    if(strcmp(buffer, "yourpass") == 0){
        flag = 1;
    }
    return flag;
}

int main(int argc, char *argv[]){
    if(argc >= 2){
        if(check_password(argv[1])){
            printf("%s", "Access granted\n");
        }else{
            printf("%s", "Access denied\n");
        }
    }else{
        printf("%s", "Please enter password!\n");
    }
}
