#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

int main(int argc, char **argv)
{
    node *head, *temp;

    head = NULL;

    for(int i=0;i<SIZE; i++)
    {
        temp = (node*)malloc(sizeof(node));
        temp->data = i;
        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
        }
        else
        {
            head->next = temp;
            temp->prev = head;
            temp->next = NULL;
        }
        head = temp;
    }

    temp = head;
    while(head->prev != NULL)
    {
        printf("%d\n", head->data);
        head = head->prev;
    }

    temp = head;
    while(head->next != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    
    return 0;
}