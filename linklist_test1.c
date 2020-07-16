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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
//struct node *delete_beg(struct node *);

int main()
{
    start = createList(start);
    display(start);
    start = insert_beg(start);
    display(start);
    insert_end(start);
    display(start);
    printf("\nHello World");
    insert_before(start);
    insert_after(start);
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

struct node *insert_before(struct node *start)
{
    struct node *new, *ptr1, *ptr2;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    printf("\nBefore insert: ");
    display(start);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    ptr1 = start;
    //ptr2 = ptr1;
    while (ptr1->data != val)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = new;
    new->next = ptr1;
    printf("\nafter insert: ");
    display(start);
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new, *ptr1, *ptr2;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    printf("\nBefore insert: ");
    display(start);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    ptr1 = start;
    ptr2 = ptr1;
    while (ptr2->data != val)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = new;
    new->next = ptr1;
    printf("\nafter insert: ");
    display(start);
    return start;
}