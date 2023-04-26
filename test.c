#include <stdio.h>
#include <stdlib.h>

// ASM Functions
int add_str(char *a, char *b); // Works
int is_palindrome_asm(char *s); // Works
int factstr(char* s);

// C Functions

int fact(int n);

int main(){

    char userinput[5];

    printf("Please enter an integer: ");
    scanf("%s", userinput);
    
    int result = factstr(userinput);
    printf("%d", result);


    return 0;
}

int fact(int n){
    if(n < 0){
        printf("Please enter an integer >= 0");
        return 0;
    }

    if(n <= 1){
        return 1;
    }

    int result = 1;
    while(n > 1){
        result = result * n;
        n--;
    }

    return result;

}