#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct NewNode{
    int value;
    struct NewNode *next;
}Node;

typedef struct NewStack {
    Node *top;
}Stack;

void errorMessage(int);
Node* create();
int isStackCreated(Node *);
int isEmpty(Node*);
void push(Node **, int, Stack *);
void pop(Node **, Stack *);
int peek(Node *);
void deleteStack(Node **, Stack *);


#endif