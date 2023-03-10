#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
    Author: Dovileu
    Date: 2023-03-10
    This module performs actions with stacks
    Stack structure is implemented using a singly linked list
*/
void errorMessage(int messageID)
{
    printf("Invalid command. ");
    switch (messageID)
    {
        case 0:
            printf("Error [%d]: Stack does not exist.\n", messageID);
        break;

        case 1:
            printf("Error [%d]: Stack is empty.\n", messageID);
        break;

        case 2:
            printf("Error [%d]: No stacks active.\n", messageID);
        break;

        case 3:
            printf("Error [%d]: Maximum amount of stacks reached.\n", messageID);
         break;

        default:
        break;
    }
}

Node* create()
{
    return (Node*)malloc(sizeof(Node));
}

int isStackCreated(Node *head)
{
    if(head != NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Node *stacks)
{
    if(stacks == NULL)
        return 1;
    return 0;
}

void push(Node **head, int element, Stack *stacks)
{
    Node *newElement = *head;
    //if stack is not empty, a new node is created
    if(!(isEmpty(stacks->top)))
    {
        newElement = (Node*)malloc(sizeof(Node));
        newElement->value = element;
        newElement->next = *head;
        *head = newElement;
    }
    else
    {
        (*head)->value = element;
    }
    stacks->top = *head;
}

void pop(Node **head, Stack *stacks)
{
    Node *temp;

    temp = *head;
    *head = (*head)->next;

    stacks->top = *head;
    if(*head != NULL)
        free(temp);
    else
        *head = temp;
}

int peek(Node *head)
{
    return head->value;
}

void deleteStack(Node **head, Stack *stacks)
{
    Node *temp;

    while (*head != NULL)
    {
       temp = *head;

       *head = (*head)->next;
       free(temp);
    }
    stacks->top = NULL;
}