
#include <stdio.h>
#include <string.h>

#define textSize 500
#define N textSize

typedef char type;

struct Stack {
    type arr[N];
    int topIndex;
};

void push(struct Stack * stack, type value) {
    stack->arr[stack->topIndex] = value;
    ++stack->topIndex;
}

type pop(struct Stack * stack) {
    --stack->topIndex;
    return stack->arr[stack->topIndex];
}

type top(const struct Stack * stack) {
    return stack->arr[stack->topIndex - 1];
}

int isEmpty(const struct Stack * stack) {
    return (!stack->topIndex);
}

void initStack(struct Stack * stack) {
    stack->topIndex = 0;
}

int isOpenedBracket(char bracket) {
    return (bracket == '(' || bracket == '[' || bracket == '{' || bracket == '<');
}

int isClosedBracket(char bracket) {
    return (bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>');
}

int isBracket(char bracketCondidate) {
    return (isOpenedBracket(bracketCondidate) || isClosedBracket(bracketCondidate));
}

char backBracket(char bracket) {
    switch (bracket) {
    case '(':
        return ')';
    case ')':
        return '(';
    case '[':
        return ']';
    case ']':
        return '[';
    case '{':
        return '}';
    case '}':
        return '{';
    case '<':
        return '>';
    case '>':
        return '<';
    }
}

char text[textSize];
struct Stack stack;

int main() {
    fgets(text, textSize, stdin);
    initStack(&stack);
    int i;
    for (i = 0; i < strlen(text); ++i) {
        char c = text[i];
        if (!isBracket(c))
            continue;
        if (isOpenedBracket(c))
            push(&stack, c);
        else {
            if (c == backBracket(top(&stack)))
                pop(&stack);
            else {
                printf("wrong\n");
                return 0;
            }
        }
    }
    printf("%s", isEmpty(&stack) ? "correct" : "wrong");
    return 0;
}