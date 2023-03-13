#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "compress.h"

#define LIST_LENGHT 10
#define INPUT_NAME_LENGHT 100

int main()
{
    FILE *inputFile;
    NodeT *head = NULL, *temp;
    int i, element;
    char inputName[INPUT_NAME_LENGHT] = "input.txt";

    while((inputFile = fopen(inputName, "r")) == NULL)
    {
        printf("Could not open input file.\n");
        printf("Please specify a new file name: ");
        scanf("%s", inputName);
    }

    for(i = 0; i < LIST_LENGHT; ++i)
    {
        while(!(fscanf(inputFile, "%d", &element)))
        {
            while(getc(inputFile) != '\n');
        }
        addNode(element, &head);
        if(head == NULL)
        {
            printf("Could not add element.\n");
            assert(0);
        }
    }

    compressList(&head);
    i = 1;
    temp = head;
    while(temp != NULL)
    {
        printf("Value No. %d: %d\n", i, temp->value);
        temp = temp->nextElement;
        ++i;
    }

    deleteList(&head);
    fclose(inputFile);

    return 0;
}
