#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
int fact(int n);
int c_palindrome(char* str);
int str_length(char* str);

int main(){
    
    char userChoice[10];
    char* test = "Hello";
    int val = 0;

    // MENU
    printf("Welcome to Erik Bowling's project 4.\n\nPick a choice from the following menu.\n\n");
    printf("  1. Add two numbers together\n");
    printf("  2. Test if a string is a palindrome (C -> ASM)\n");
    printf("  3. Print the factorial of a number\n");
    printf("  4. Test if a string is a palindrome (ASM -> C)\n");

    // Returns 0 if no valid conversion can be made;
    while(val == 0){
        printf("\nChoice: ");
        scanf("%s", userChoice);
        val = atoi(userChoice);
    }

    printf("%d", val);
    
    switch(val){

        case 1:
            break;

        case 2:
            break;
        
        case 3:

            int fact_num = 0;
            printf("\nFACTORIAL: ");
            printf("\nNumber to factorialize: ");

            scanf("%s", userChoice);
            fact_num = atoi(userChoice);
            printf("%d", fact(fact_num));
            break;
        
        case 4:
            break;

        default:
            break;

    }

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
    for(n; n > 0; n--){
        result = result * n;
    }

    return result;
}

int c_palindrome(char* str){
    int len = str_length(str);
}

int str_length(char* str){
    int count = 0;

    while(1){
        if(str[count] == '\0'){
            break;
        }

        count++;
    }

    return count;

}