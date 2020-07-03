#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct Node
{
    struct Node *next;
    int data;
} LISTITEM;

int main(int argc, char **argv)
{
    LISTITEM *listhead, *temp;

    listhead = NULL;
    for(int i=0;i<SIZE;i++)
    {
        temp = (LISTITEM*) malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = listhead;
        listhead = temp;
    }

    temp = listhead;
    while(temp != NULL)
    {
        printf("list item: current is %p, next is %p, data is %d\n", temp, temp->next, temp->data);
        temp = temp->next;
    }
    
    return 0;
}
