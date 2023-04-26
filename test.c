#include <stdio.h>
#include <stdlib.h>

int add_str(char *a, char *b); // Works
int is_palindrome_asm(char *s); // Works

int main(){

    char userinput[1024];

    printf("Please enter in a string: \n");
    scanf("%s", userinput);
    
    if(is_palindrome_asm(userinput) == 1){
        printf("Palindrome!");
    }else{
        printf("Not palindrome!");
    }



    return 0;
}