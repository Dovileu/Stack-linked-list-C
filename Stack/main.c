#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_COUNT 10

void inputIDMessage(int *arrNum)
{
    printf("Input stack ID:\n");
    printf("--> ");
    scanf("%d", arrNum);
}

int main()
{
    int select = 0;

    int element, arrCount = 0, arrNum = 1;
    Node *head[STACK_COUNT];
    Stack stacks[STACK_COUNT];

    for(int i = 0; i < STACK_COUNT; ++i)
    {
        head[i] = NULL;
        stacks[i].top = NULL;
    }

    while(select != 8)
    {
        printf("\n");
        printf("Please input a command. Select number 1-8\n");
        printf("Available commands:\n");
        printf("(1) Create stack.\n");
        printf("(2) Check if empty.\n");
        printf("(3) Push.\n");
        printf("(4) Pop.\n");
        printf("(5) Peek.\n");
        printf("(6) Show active stack count.\n");
        printf("(7) Destroy stack.\n");
        printf("(8) Terminate program.\n");
        printf("--> ");

        arrNum = 0;
        //if only one stack active, checking it's ID
        for(int i = 0; i < STACK_COUNT; ++i)
        {
            if(isStackCreated(head[i]))
            {
                arrNum = i;
                continue;
            }
        }

        scanf("%d", &select);

        system("cls");

        if(select != 1 && select != 6 && select != 8 && arrCount > 1)
        {
            inputIDMessage(&arrNum);

            if(arrNum > STACK_COUNT || arrNum < 0 || !isStackCreated(head[arrNum]))
            {
                errorMessage(0);
                continue;
            }
        }
        else if(select != 1 && select != 6 && select != 8 && arrCount == 0)
        {
            errorMessage(2);
            continue;
        }

        switch (select)
        {
            case 1:
                if(arrCount >= STACK_COUNT)
                {
                    errorMessage(3);
                    break;
                }
                for(int i = 0; i < STACK_COUNT; ++i)
                {
                    if(!isStackCreated(head[i]))
                    {
                        head[i] = create();
                        head[i]->next = NULL;
                        stacks[i].top = NULL;
                        arrCount++;
                        printf("Stack ID %d created.\n", i);
                        break;
                    }
                }
            break;

            case 2:
            if(isEmpty(stacks[arrNum].top))
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;

            case 3:
                printf("Input a whole number to push:\n");
                scanf("%d", &element);
                push(&head[arrNum], element, &stacks[arrNum]);
                printf("Number %d was pushed to stack ID %d.\n", element, arrNum);
            break;

            case 4:
                if(isEmpty(stacks[arrNum].top))
                {
                    errorMessage(1);
                    break;
                }
                pop(&head[arrNum], &stacks[arrNum]);
                printf("Element popped from stack ID %d.\n", arrNum);
            break;

            case 5:
            if(isEmpty(stacks[arrNum].top))
            {
                errorMessage(1);
                break;
            }
            printf("Topmost element in stack ID %d: %d.\n", arrNum, peek(head[arrNum]));
            break;

            case 6:
            printf("%d stacks active right now:\n", arrCount);
            for(int i = 0; i < STACK_COUNT; ++i)
            {
                if(isStackCreated(head[i]))
                {
                    printf("Stack ID %d.\n", i);
                }
            }
            break;

            case 7:
            deleteStack(&head[arrNum], &stacks[arrNum]);
            printf("Stack ID %d destroyed.\n", arrNum);
            --arrCount;
            break;

            case 8:
            printf("Program terminated.\n");
            break;

            default:
            errorMessage(2);
            break;
        }
    }

    for(int i = 0; i < STACK_COUNT; ++i)
    {
        if(isStackCreated(head[i]))
            deleteStack(&head[i], &stacks[i]);
    }

    return 0;
}
