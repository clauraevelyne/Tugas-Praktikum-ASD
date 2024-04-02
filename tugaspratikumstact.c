#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struktur Stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Operasi-operasi Stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

//Mengecek apakah stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

//Menambahkan Elemen ke dalam stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

//Menghapus Elemen dari stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Fungsi untuk mengecek keseimbangan tanda kurung
char* isBalanced(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return "NO";

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(stack, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(stack))
                return "NO";
            char popped = pop(stack);
            if ((exp[i] == ')' && popped != '(') || (exp[i] == '}' && popped != '{') || (exp[i] == ']' && popped != '['))
                return "NO";
        }
    }

    return isEmpty(stack) ? "YES" : "NO";
}

int main() {
    char exp[MAX_SIZE];
    printf("Masukkan urutan tanda kurung: ");
    scanf("%s", exp);
    printf("%s\n", isBalanced(exp));
    return 0;
}

