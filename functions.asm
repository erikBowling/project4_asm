; Name: Erik Bowling
; Date: April 24, 2023
; Project 4 ASM Functions

BITS 32

GLOBAL is_palindrome_asm, add_str, factstr, palindrome_check
EXTERN atoi, fact, is_palindrome_c

SECTION .data
    prompt db "Please enter a string", 0xa
    lenPrompt EQU $ - prompt

    succ db "The string IS a palindrome", 0xa
    lenSucc EQU $ - succ

    failure db "The string IS NOT a palindrome", 0xa
    lenFailure EQU $ - failure

SECTION .bss
    user_string resb 1024

SECTION .text

is_palindrome_asm:
    push ebp ; Preserve location of ebp
    mov ebp, esp ; Make ebp point to top of the stack
    push esi 
    push ebx

    mov esi, [ebp+8]

    xor ebx, ebx
    _get_str_length:
        cmp BYTE [esi + ebx], 0
        je _have_length

        inc ebx
        jmp _get_str_length

    _have_length:
        dec ebx
        mov edx, ebx ; move length into edx
        xor ecx, ecx ; zero out ecx 
        shr ebx, 1 ; Easier divide by two.

    _check_palindrome:
        mov ah, BYTE [esi + ecx] ; storing characters starting from the beginning in ah

        cmp ah, BYTE [esi + edx] ; compare beginning character to end character
        jne _not_pal

        cmp edx, ebx ; If edx exceeds ebx or is equal, then we have a palindrome
        jge _yes_pal

        inc edx
        dec ecx

        jmp _check_palindrome

    _not_pal:
        ; return 0 if not palindrome
        xor eax, eax
        jmp _done

    _yes_pal:
        ; return 1 if palindrome
        xor eax, eax
        inc eax

    _done:
        ; Restore esi, and ebx
        pop ebx
        pop esi

        ; Reset ebp
        mov esp, ebp
        pop ebp

    ret



add_str:
    push ebp ; Preserve location of ebp
    mov ebp, esp ; Make ebp point to top of the stack
    push ebx ; store ebx for our caller

    push DWORD [ebp+8] ; First call to atoi. Expects the argument to be pushed
    call atoi

    mov ebx, eax ; Store result from first atoi in ebx

    push DWORD [ebp+12] ; Second call to atoi. Passing in second argument
    call atoi

    add eax, ebx ; Add first call's result to the second

    add esp, 8 ; Remove local variable space

    pop ebx ; restore value of ebx

    mov esp, ebp
    pop ebp

    ret

factstr:
    push ebp
    mov ebp, esp

    push DWORD [ebp+8]
    call atoi

    push eax
    call fact

    mov esp, ebp
    pop ebp
    ret

palindrome_check:
    push ebp
    mov ebp, esp
    push ebx

    ; Print the prompt
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, lenPrompt
    int 80h

    ; Take in user string
    mov eax, 3
    mov ebx, 0
    mov ecx, user_string
    mov edx, 1024
    int 80h

    push user_string
    call is_palindrome_c

    add esp, 4 ; remove the pushed userstring

    cmp eax, 1
    je _success
    jne _fail

    _success:
        mov eax, 4
        mov ebx, 1
        mov ecx, succ
        mov edx, lenSucc
        int 80h
        jmp _fin

    _fail:
        mov eax, 4
        mov ebx, 1
        mov ecx, failure
        mov edx, lenFailure
        int 80h

    _fin:

    pop ebx
    mov esp, ebp
    pop ebp
    ret