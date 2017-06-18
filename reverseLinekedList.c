#include <stdio.h>
#include <stdlib.h>

// Variables
typedef struct node {
    int value;
    struct node *next;
} mynode;
// Globals (not required, though).
mynode *head, *tail, *temp;
// Functions
void add(int value);
void iterative_reverse();
void print_list();


int main()
{
    head = (mynode *)0;

    // Construct the linked list.
    add(1);
    add(2);
    add(3);
    print_list();
    iterative_reverse();
    print_list();
    return (0);
}
// The reverse function
void iterative_reverse()
{
    mynode *p, *q, *r;
    if (head == (mynode *)0) {
        return;
    }

    p = head;
    q = p->next;
    p->next = (mynode *)0;
    while (q != (mynode *)0) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
}
// Function to add new nodes to the linked list
void add(int value)
{
    temp = (mynode *)malloc(sizeof(struct node));
    temp->next = (mynode *)0;
    temp->value = value;

    if (head == (mynode *)0) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
// Function to print the linked list.
void print_list()
{
    printf("\n\n");
    for (temp = head; temp != (mynode *)0; temp = temp->next) {
        printf("[%d]->", (temp->value));
    }
    printf("[NULL]\n\n");
}
