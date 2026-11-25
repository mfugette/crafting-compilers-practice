#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[1];
    struct Node *next;
    struct Node *prev;
} Node;

Node *insert_at_start(Node *head, char value[]);
Node *insert_at_end(Node *head, char value[]);

Node *new_node(char value[]);
void print_list(Node *head);

int main()
{

    Node *head = new_node("A");

    head->next = new_node("B");
    head->next->prev = head;

    head->next->next = new_node("C");
    head->next->next->prev = head->next;

    head->next->next->next = new_node("D");
    head->next->next->next->prev = head->next->next;

    printf("Before inserts: \n");
    print_list(head);

    head = insert_at_start(head, "X");

    printf("Insert at start: \n");
    print_list(head);

    head = insert_at_end(head, "Y");

    // TODO: Figure out how to print the whole list, not just the tail.
    printf("Insert at end: \n");
    print_list(head);

    return 0;
}

Node *insert_at_start(Node *head, char value[])
{
    Node *n = new_node(value);

    n->next = head;
    n->next->prev = n->next;

    return n;
}

Node *insert_at_end(Node *head, char value[])
{
    Node *tail = new_node(value);

    struct Node *temp = head;
    print_list(temp);

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            temp->next = tail;
            temp->next->prev = temp->next;
            return temp;
        }
        temp = temp->next;
    }

    return tail;
}

void find()
{
}

void delete()
{
}

// Helper Functions

Node *new_node(char value[])
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error: malloc failed in new_node()");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->data, value);

    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void print_list(Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(temp->data);
        temp->next != NULL
            ? printf(" <-> ")
            : printf("\n");
        temp = temp->next;
    }
}
