#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *t1 = tail1;
    node *t2 = tail2;

    node *headR1 = NULL, *tailR1 = NULL, *headR2 = NULL, *tailR2 = NULL;

    int data, carry, count = 0;

    // Traverse second number from last digit to first digit
    while(t2 != NULL)
    {
        // Reset t1 to last node of first number for each digit of second number
        t1 = tail1;
        // Reset carry for each iteration
        carry = 0;
         // Reset intermediate result list
        headR1 = tailR1 = NULL;
        
        while(t1 != NULL)
        {
            int temp;
            // Multiply digits and add carry
            temp = (t1->data * t2->data) + carry;

            // Store single digit result
            data = temp % 10;
           
            // Update carry
            carry = temp / 10;

            // Insert result digit at beginning (reverse order handling)
            insert_first(&headR1, &tailR1, data);

            t1 = t1->prev;

        }
        // If carry remains after full multiplication
        if(carry)
        {
            insert_first(&headR1, &tailR1, carry);
        }

        // Shift result left by adding zeros (like multiplying by 10, 100, etc.)
        for(int i=0;i<count;i++)
        {
            insert_last(&headR1, &tailR1, 0);
        }
        // If result list is empty (first multiplication step)
        if(*headR == NULL)
        {
            *headR = headR1;
            *tailR = tailR1;
        }
        else
        {
            // Add previous result with current partial result
            addition(*headR, *tailR,headR1, tailR1,&headR2, &tailR2,'+','+');

            // Delete old result list to avoid memory leak
            delete_list(headR, tailR);

            // Update result pointers
            *headR = headR2;
            *tailR = tailR2;

            // Reset temp pointers
            headR2 = NULL;
            tailR2 = NULL;
        }


        t2 = t2->prev;
        count++;
    }

    // Remove leading zeros from final result
    remove_pre_zeros(headR);

    // If result becomes empty, make it 0
    if(*headR == NULL)
    {
        insert_last(headR, tailR, 0);
    }

    
}
