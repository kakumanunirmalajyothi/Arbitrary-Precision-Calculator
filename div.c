#include "apc.h"

int division(node *head1, node *head2, node **headR, node **tailR)
{
    
    int count = 0;
    node *tail1 = NULL;
    node *tail2 = NULL;
    

    // Check invalid input lists
    if (head1 == NULL || head2 == NULL) 
    {
        printf("Invalid input\n");
        return FAILURE;
    }
    
    // Check division by zero condition
    if(head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Division by zero not possible\n");

        // Set result to NULL
        *headR = NULL;
        *tailR = NULL;

        return FAILURE;
    }

    // Repeat subtraction until dividend < divisor
    while (compare_list(head1, head2) != OPERAND2)
    {
        // Reset result list for each subtraction
        *headR = NULL;
        *tailR = NULL;

        // finding tail of dividend(last node)
        tail1 = head1;
        while(tail1->next != NULL)
        {
            tail1 = tail1->next;
        }


        // finding tail of divisor(last node)
        tail2 = head2;
        while(tail2->next != NULL)
        {
            tail2 = tail2->next;
        }

        // Perform subtraction: head1 = head1 - head2
        subtraction(tail1, tail2, headR, tailR);

        // Increase quotient count
        count++;

        // Delete old dividend list
        delete_list(&head1, &tail1);

        // Update dividend with new reduced value
        head1 = *headR;
        tail1 = *tailR;
    }
    
    // convert quotient integer to string
    char buffer[50];
    sprintf(buffer, "%d", count);

    // build quotient list
    *headR = NULL;
    *tailR = NULL;

    // Create linked list from quotient string
    create_list(buffer, headR, tailR);

    return SUCCESS;
     
}
