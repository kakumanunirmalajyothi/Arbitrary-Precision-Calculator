#include "apc.h"

// Function to subtract two numbers using doubly linked list
// tail1 and tail2 are the last nodes of the two numbers
// Result is stored in headR and tailR
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *t1 = tail1;
    node *t2 = tail2;
    int borrow = 0;

    // Traverse until first number digits are completed
    while (t1 != NULL)
    {
        // Variable to store subtraction result of current digit
        int diff;

        if (t2 != NULL)
        {
            // Subtract both digits and previous borrow
            diff = t1->data - t2->data - borrow;
        }
        else
        {
            // If second number has no digits,
            // subtract only borrow from first number
            diff = t1->data - borrow;
        }

        if (diff < 0)
        {
            // Add 10 to make digit positive
            // Example: 2 - 5 = -3 -> 7
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, diff);

        t1 = t1->prev;
        if (t2 != NULL) 
        {
            t2 = t2->prev;
        }
    }
    
    remove_pre_zeros(headR);


    // 5 - 5 = 0
    if(*headR == NULL)
    {

        node *new = malloc(sizeof(node));


        if(new == NULL)
        {
            return;
        }


        new->data = 0;
        new->prev = NULL;
        new->next = NULL;


        *headR = new;
        *tailR = new;

    }

}
