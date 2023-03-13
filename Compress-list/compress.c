#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "compress.h"

void addNode(int element, NodeT **head)
{
    NodeT *newElement = *head;

    newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->value = element;
    newElement->nextElement = *head;
    *head = newElement;
}

void compressList(NodeT **head)
{
    NodeT *tempCurrent, *tempNext, *tempFree;

    tempCurrent = *head;
    while(tempCurrent->nextElement)
    {  
        tempNext = tempCurrent->nextElement;
        //Check if current element is equal to the next
        if(tempCurrent->value == tempNext->value)
        {
            tempFree = tempNext;
            //skip the element and free memory allocated to it
            tempNext = tempNext->nextElement;
            free(tempFree);
            tempCurrent->nextElement = tempNext;
        }
        else
        {
            tempCurrent = tempNext;
        }
    }
    
}
void deleteList(NodeT **head)
{
    NodeT *temp;

    while (*head != NULL)
    {
       temp = *head;

       *head = (*head)->nextElement;
       free(temp);
    }
}