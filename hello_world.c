#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[10];
    struct Node *next;
    struct Node *prev;
} Node;

Node *newNode(char value[])
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    strcpy(newNode->data, value);

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int main()
{

    Node *head = newNode("FIRST");

    head->next = newNode("SECOND");
    head->next->prev = head;

    head->next->next = newNode("THIRD");
    head->next->next->prev = head->next;

    head->next->next->next = newNode("FOURTH");
    head->next->next->next->prev = head->next->next;

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf(temp->data);
        if (temp->next != NULL)
        {
            printf(" <-> ");
        }
        temp = temp->next;
    }

    return 0;
}

void insert()
{
}

void find()
{
}

void delete()
{
}
