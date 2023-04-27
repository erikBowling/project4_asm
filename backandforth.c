// Name: Erik Bowling
// Date: April 27, 2023
// Assignment: 3410 Project 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************** ASM FUNCTIONS **************/

/*  
    Function takes two strings entered from C
    converts both with atoi from ASM,
    then returns them added together.
    The program expects them to be integers

    @param a char *
    @param b char *
    
    @returns int(a + b)
*/
int add_str(char *a, char *b);

/*  
    Function takes in a string in c, and passes it to an 
    ASM function that will check if it is a palindrome

    @param s char *
    
    @returns 1 if palindrome or 0 if not
*/
int is_palindrome_asm(char *s);

/*  
    Takes in a string that should be an integer from c
    In ASM, it converts the string to an integer and calls
    fact defined in C.

    @param s char *
    
    @returns s!
*/
int factstr(char* s);

/*  
    Function takes in a string in ASM and calls the c palindrome
    check function defined below.

    Will print whether the string is a palindrome or not

*/
void palindrome_check();

/************** C FUNCTIONS **************/

/*  
    Function takes in an integer and returns it's factorial

    @param n int

    @returns n!
    
*/
int fact(int n);

/*  
    Function takes in a string and returns true or false
    whether it is a factorial or not

    @param s char *

    @returns 0 if not a palindrome or 1 if so
    
*/
int is_palindrome_c(char* s);

int main(){
    /* *** Variables ***  */

    // Menu selection vars
    char userChoice[10] = "";
    int userVal = 0;

    // Add two numbers vars
    char addNum1[10] = "";
    char addNum2[10] = "";

    // is_palindrome_asm vars
    char pal_str_asm[1024] = "";

    // Factorial vars
    char fact_str[20] = "";
    int fact_num = 0;

    int running = 1;

    printf("Welcome to Erik Bowling's project 4.\n\nPick a choice from the following menu.");

    // Main loop
    while(running){
        // MENU
        printf("\n\n  ***** MENU *****\n\n");
        printf("  1. Add two numbers together\n");
        printf("  2. Test if a string is a palindrome (C -> ASM)\n");
        printf("  3. Print the factorial of a number\n");
        printf("  4. Test if a string is a palindrome (ASM -> C)\n");
        printf("  5. Exit the program\n");
        printf("\n  ******************\n");

        // ATOI returns 0 if no valid conversion can be made;
        while(userVal == 0){
            printf("\nChoice: ");
            scanf("%s", userChoice);
            userVal = atoi(userChoice);
        }
        
        // Switch on user input
        switch(userVal){

            // add_str(char *, char *) -> ASM function
            case 1:
                printf("\n  **** ADD STRINGS ASM ****\n\n");
                printf("Please enter an integer: ");
                scanf("%s", addNum1);
                printf("Please enter another integer: ");
                scanf("%s", addNum2);
                printf("ANSWER: ");
                printf("%d\n", add_str(addNum1, addNum2));

                break;

            // is_palindrome_asm(char *) -> ASM function
            case 2:
                printf("\n  **** IS_PALINDROME_ASM ****\n\n");
                printf("Please enter a string: ");
                scanf("%s", pal_str_asm);
                if(is_palindrome_asm(pal_str_asm)){
                    printf("\nThe string IS a palindrome\n");
                }else{
                    printf("\nThe string IS NOT a palindrome\n");
                }

                break;
            
            // fact_str(char *) -> ASM function
            case 3:
                printf("\n  **** FACTORIAL ****\n");
                printf("\nNumber to factorialize: ");

                scanf("%s", fact_str);
                fact_num = factstr(fact_str);
                printf("\nANSWER: %d", fact_num);
                break;
            
            // palindrome_check() -> ASM function
            case 4:
                palindrome_check();
                break;

            case 5:
                printf("\n  **** GOODBYE ****\n");
                return 0;

            default:
                break;

        }

        userVal = 0;
    } // End main while

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