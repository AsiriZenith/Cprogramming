#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *createList(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
    int n;
    do
    {
        printf("\n\n*************************************MAIN MENU***************************************");
        printf("\n 1: Create a list ");
        printf("\n 2. Display the list");
        printf("\n 3. Add a node at the beginning");
        printf("\n 4. Add a node at the end");
        printf("\n 5. Add a node before a given node");
        printf("\n 6. Add a node after a given node");
        printf("\n 7. Delete a node from the begining");
        printf("\n 8. Delete a node from the end");
        printf("\n 9. Delete a given node");
        printf("\n 10. Delete a node after a given node");
        printf("\n 11. Delete the entire list");
        printf("\n 12. Sort the list");
        printf("\n 13. Exit");
        printf("\n Enter your option : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            start = createList(start);
            printf("\n\nLinked list Created!!");
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            insert_end(start);
            break;
        case 5:
            insert_before(start);
            break;
        case 6:
            insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            delete_end(start);
            break;
        case 9:
            delete_node(start);
            break;
        case 10:
            delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n\nLinked list Deleted!!");
            break;
        case 12:
            start = sort_list(start);
            break;
        default:
            break;
        }
    } while (n != 13);

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
    printf("\nBefore insert: ");
    display(start);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = start;
    start = new;
    printf("\nafter insert: ");
    display(start);
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nBefore insert: ");
    display(start);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    printf("\nafter insert: ");
    display(start);
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

struct node *delete_beg(struct node *start)
{
    printf("\nBefore delete: ");
    display(start);
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    printf("\nafter delete: ");
    display(start);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr1, *ptr2;
    printf("\nBefore delete: ");
    display(start);
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    free(ptr1);
    printf("\nafter delete: ");
    display(start);
    return start;
}

struct node *delete_node(struct node *start)
{
    int num;
    struct node *ptr1, *ptr2;
    printf("\nEnter the value which does you want to delete : ");
    scanf("%d", &num);
    printf("\nBefore delete: ");
    display(start);
    ptr1 = start;
    while (ptr1->data != num)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = ptr1->next;
    free(ptr1);
    printf("\nafter delete: ");
    display(start);
    return start;
}

struct node *delete_after(struct node *start)
{
    int num;
    struct node *ptr1, *ptr2;
    printf("\nEnter the value after which the node has to deleted : ");
    scanf("%d", &num);
    printf("\nBefore delete: ");
    display(start);
    ptr1 = start;
    while (ptr1->data != num)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    printf("\nafter delete: ");
    display(start);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    ptr1 = start;
    if (ptr1 == NULL)
    {
        printf("\nNothing anything here!!");
    }
    else
    {
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            free(ptr2);
        }
        free(ptr1);
    }
    return NULL;
}

struct node *sort_list(struct node *start)
{
    int i, j, temp, k = 0;
    struct node *ptr1, *ptr2;
    ptr1 = start;
    printf("\nbefore sorting : ");
    display(start);
    //determine the lengh of linked list
    while (ptr1->next != NULL)
    {
        k++;
        ptr1 = ptr1->next;
    }
    for (i = 0; i < k; i++)
    {
        ptr1 = start;
        ptr2 = ptr1->next;
        for (j = 0; j < k - i; j++)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
    }
    printf("\nafter sorting : ");
    display(start);
    return start;
}