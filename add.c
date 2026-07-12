#include "apc.h"

// Function to add two numbers using doubly linked list
// tail1 and tail2 point to last nodes of both numbers
// headR and tailR store the result list
void addition(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR, char sign1, char sign2)
{
    
    node *t1 = tail1;
    node *t2 = tail2;

    int data;
    int carry = 0;

    // Both numbers have digits
    // Example: 72 + 12
    if(sign1 == '+' && sign2 == '+')
    {
        while(t1 != NULL && t2 != NULL)
        {
            // Add current digits along with previous carry
            data = t1->data + t2->data + carry;

            // Calculate carry
            // Example: 8+7 = 15, carry = 1
            carry = data / 10;

            // Keep only single digit in result
            // Example: 15 becomes 5
            data = data % 10;

            // Insert result digit at beginning of result list
            // because we are moving from tail to head
            insert_first(headR, tailR, data);

            // Move both pointers to previous nodes
            t1 = t1->prev;
            t2 = t2->prev;   
        }
        
        
        // Remaining digits in first number
        // Example: 98 + 2
        while(t1 != NULL)
        {
            data = t1->data + carry;

            carry = data / 10;
            data = data % 10;

            insert_first(headR, tailR, data);

            t1 = t1->prev;
                
        }

        // Remaining digits in second number
        while(t2 != NULL)
        {
            data = t2->data + carry;

            carry = data / 10;
            data = data % 10;

            insert_first(headR, tailR, data);

            t2 = t2->prev;
                
        }

        // After all additions, if carry is still present
        // Example: 99 + 1 = 100
        if(carry)
        {
            insert_first(headR, tailR, carry);
        }
    }


    //  both negative
    // -2 + -3 = -(2+3)
    else if(sign1 == '-' && sign2 == '-')
    {
        result_negative = 1;
        addition(head1, tail1, head2, tail2, headR, tailR,'+','+');
    }


    // first positive, second negative
    // 5 + (-2) = 5 - 2
    else if(sign1 == '+' && sign2 == '-')
    {
        if(compare_list(head1, head2) == OPERAND1 || compare_list(head1, head2) == SAME)
        {
            subtraction(tail1, tail2, headR, tailR);
        }
        else
        {
            subtraction(tail2, tail1, headR, tailR);
        }
    }


    // first negative, second positive
    // -5 + 2 = -(5 - 2)
    else if(sign1 == '-' && sign2 == '+')
    {
        if(compare_list(head1, head2) == OPERAND1)
        {
            result_negative = 1;
            subtraction(tail1, tail2,headR, tailR);
        }
        else
        {
            result_negative = 0;
            subtraction(tail2, tail1, headR, tailR);
        }
    }

}
