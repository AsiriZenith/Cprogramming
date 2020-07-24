#include <stdio.h>
#include <stdlib.h>

// This Node containing power, coefficient of variable and next point
struct node
{
    int coeff;
    int pow;
    struct node *next;
};

// Function add a new node at the end of list
void create_node(int p, int q, struct node **temp)
{
    struct node *a, *b;
    b = *temp;
    if (b == NULL)
    {
        a = (struct node *)malloc(sizeof(struct node));
        a->coeff = p;
        a->pow = q;
        *temp = a;
        a->next = (struct node *)malloc(sizeof(struct node));
        a = a->next;
        a->next = NULL;
    }
    else
    {
        a->coeff = p;
        a->pow = q;
        a->next = (struct node *)malloc(sizeof(struct node));
        a = a->next;
        a->next = NULL;
    }
}

// Functionn To Display The Linked list
void showFunction(struct node *n)
{
    while (n->next != NULL)
    {
        printf("%dx^%d", n->coeff, n->pow);
        n = n->next;
        if (n->next != NULL)
        {
            printf(" + ");
        }
    }
}

void Add(struct node *poly1, struct node *poly2, struct node *poly)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->next < poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly->next || poly->next)
    {
        if (poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Function to add coefficients of two elements having same powerer
// void removeDuplicates(struct node *poly)
// {
//     struct node *ptr1, *ptr2, *dup;
//     ptr1 = poly;

//     while (ptr1 != NULL && ptr1->next != NULL)
//     {
//         ptr2 = ptr1;

//         while (ptr2->next != NULL)
//         {
//             if (ptr1->pow == ptr2->next->pow)
//             {
//                 ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
//                 dup = ptr2->next;
//                 ptr2->next = ptr2->next->next;

//                 delete(dup);
//             }
//             else
//             {
//                 ptr2 = ptr2->next;
//             }
//         }
//         ptr1 = ptr1->next;
//     }
// }

// Function two Multiply two polynomial Numbers
// struct node *Multiplication(struct node *poly1, struct node *poly2, struct node *poly)
// {
//     struct node *ptr1, *ptr2;
//     ptr1 = poly1;
//     ptr2 = poly2;

//     while (ptr1 != NULL)
//     {
//         while (ptr2 != NULL)
//         {
//             int coeff, power;

//             coeff = ptr1->coeff * ptr2->coeff;

//             power = ptr1->pow + ptr2->pow;

//             poly = addnode(coeff, power, poly);

//             ptr2 = ptr2->next;
//         }
//         ptr2 = poly2;

//         ptr1 = ptr1->next;
//     }
//     removeDuplicates(poly);
//     return poly;
// }

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    poly = (struct node *)malloc(sizeof(struct node));

    create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);

    create_node(5, 1, &poly2);
    create_node(5, 0, &poly2);

    printf("\n1st Polynomial: ");
    showFunction(poly1);

    printf("\n2nd Polynomial: ");
    showFunction(poly2);

    Add(poly1, poly2, poly);

    printf("\nAdded polynomial: ");
    showFunction(poly);

    // poly1 = addnode(poly1, 3, 2);
    // poly1 = addnode(poly1, 5, 1);
    // poly1 = addnode(poly1, 6, 0);

    // printf("\n1st Polynomial: ");
    // showFunction(poly);

    // printf("\n2nd Polynomial: ");
    // showFunction(poly2);

    // poly = Multiplication(poly1,poly2,poly);
    // showFunction(poly);
    return 0;
}
