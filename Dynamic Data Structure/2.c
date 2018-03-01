
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define textSize 500
#define N textSize

typedef char type;

struct Stack {
    struct StackElem * topElem;
    size_t size;
};

struct StackElem{
    type value;
    struct StackElem * next;
};

void push(struct Stack * stack, type value) {
    struct StackElem * node = (struct StackElem *)malloc(sizeof(struct StackElem));
    node->value = value;
    node->next = stack->topElem;
    stack->topElem = node;
    ++stack->size;
}

type pop(struct Stack * stack) {
    struct StackElem * node = stack->topElem;
    type result = node->value;
    stack->topElem = node->next;
    free(node);
    --stack->size;
    return result;
}

type top(const struct Stack * stack) {
    return (stack->topElem ? stack->topElem->value : NULL);
}

int isEmpty(const struct Stack * stack) {
    return (!stack->size);
}

void initStack(struct Stack * stack) {
    stack->topElem = NULL;
    stack->size = 0;
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
            if (isEmpty(&stack) || c != backBracket(top(&stack))) {
                printf("wrong\n");
                return 0;
            } else 
                pop(&stack);
        }
    }
    printf("%s", isEmpty(&stack) ? "correct" : "wrong");
    return 0;
}