#ifndef COMPRESS_H_INCLUDED
#define COMPRESS_H_INCLUDED

typedef struct Node{
    int value;
    struct Node *nextElement;
}NodeT;

void addNode(int, NodeT**);
void compressList(NodeT**);
void deleteList(NodeT**);

#endif