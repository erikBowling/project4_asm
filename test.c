#include <stdio.h>
#include <stdlib.h>

// ASM Functions
int add_str(char *a, char *b); // Works
int is_palindrome_asm(char *s); // Works
int factstr(char* s);
void palindrome_check();

// C Functions

int fact(int n);
int is_palindrome_c(char* s);

int main(){

    palindrome_check();

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

int is_palindrome_c(char* s){
    int len = 0;
    int i, j;

    while(s[len] != '\0')
        len++;
        
    i = 0;
    j = len - 2;

    while(i < len / 2){
        if(s[i] != s[j]) return 0;
        i++;
        j--;
    }

    return 1;
}