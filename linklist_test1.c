#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;
struct node *createList(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
//struct node *insert_before(struct node *);

int main()
{
    start = createList(start);
    display(start);
    start = insert_beg(start);
    display(start);
    insert_end(start);
    display(start);
    printf("\nHello World");

    return 0;
}

struct node *createList(struct node *start)
{
    struct node *new, *ptr;
    int num;
    printf("\nEnter -1 to End");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new = (struct node *)malloc(sizeof(struct node *));
        new->data = num;
        if (start == NULL)
        {
            new->next = NULL;
            start = new;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new;
            new->next = NULL;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nNothing Any Value!!");
    }
    else
    {
        ptr = start;
        printf("\nData List:");
        do
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        } while (ptr->next != NULL);
        printf("\t%d", ptr->data);
    }

    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = start;
    start = new;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return start;
}