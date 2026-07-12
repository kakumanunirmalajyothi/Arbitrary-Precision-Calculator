#include "apc.h"

// Function definitions

// Global variable used to store whether result is negative or not
int result_negative = 0;

// Function to validate command line arguments
int cla_validation(int argc, char *argv[])
{
    // Check if no arguments are passed
    if(argc == 1)
    {
        printf("ERROR : Invalid Operation\n");
        printf("Usage : ./a.out <operand 1> <operator> <operand 2>\n");
        return FAILURE;
    }

    // Check number of arguments
    if(argc != 4)
    {
        printf("ERROR : Invalid Operation\n");
        printf("Usage : ./a.out <operand 1> <operator> <operand 2>\n");
        return FAILURE;
    }

    // Check whether operator is valid
    if(argv[2][0]!= '+' && argv[2][0]!= '-' && argv[2][0]!= 'x' && argv[2][0]!= '/')
    {
        printf("ERROR : Invalid Operator\n");
        return FAILURE;
    }

    // Operand 1 validation
    int digit_count = 0;

    for(int i = 0; argv[1][i] != '\0'; i++)
    {
        if(argv[1][i] == '+' || argv[1][i] == '-')
        {
            if(i != 0)
            {
                printf("ERROR : Invalid Operand\n");
                return FAILURE;
            }
        }
        else if(argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            digit_count++;
        }
        else
        {
            printf("ERROR : Invalid Operand\n");
            return FAILURE;
        }
    }


    // only + or - is invalid
    if(digit_count == 0)
    {
        printf("ERROR : Invalid Operand\n");
        return FAILURE;
    }



    // Operand 2 validation
    digit_count = 0;

    for(int i = 0; argv[3][i] != '\0'; i++)
    {
        if(argv[3][i] == '+' || argv[3][i] == '-')
        {
            if(i != 0)
            {
                printf("ERROR : Invalid Operand\n");
                return FAILURE;
            }
        }
        else if(argv[3][i] >= '0' && argv[3][i] <= '9')
        {
            digit_count++;
        }
        else
        {
            printf("ERROR : Invalid Operand\n");
            return FAILURE;
        }
    }


    if(digit_count == 0)
    {
        printf("ERROR : Invalid Operand\n");
        return FAILURE;
    }


    return SUCCESS;
}

// Function to create doubly linked list from operand
void create_list(char *opr, node **head, node **tail)
{
    int data;
    // Traverse operand string
    for(int i=0; opr[i]!='\0'; i++)
    {
        // Skip signs (+ and -)
        if(opr[i] == '+' || opr[i] == '-')
        {
            continue;
        }
        // Convert character digit into integer
        data = opr[i] - '0';
        // Insert digit at last
        insert_last(head, tail, data);
    }
}

// Function to insert node at beginning
int insert_first(node **head, node **tail, int data)
{
    // Allocate memory for new node
    node *new = malloc(sizeof(node));
    
    // Check memory allocation
    if(new == NULL)
    {
        return FAILURE;
    }

    // Store data in new node
    new->data = data;

    // Initialize links
    new->prev = NULL;
    new->next = NULL;

    // If list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    // Connect new node before head
    new->next = *head;
    (*head)->prev = new;
    
    // Update head
    *head = new;

    return SUCCESS;

}

// Function to insert node at end
int insert_last(node **head, node **tail, int data)
{
    // Allocate memory for new node
    node *new = malloc(sizeof(node));

    // Check memory allocation
    if(new == NULL)
    {
        return FAILURE;
    }

    // Store data in new node
    new->data = data;

    // Initialize links
    new->prev = NULL;
    new->next = NULL;

    // If list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    // Connect new node after tail
    new->prev = *tail;
    (*tail)->next = new;

    // Update tail
    *tail = new;
    return SUCCESS;
}

// Function to print doubly linked list
int print_list(node *head)
{
    // Check empty list
    if(head == NULL)
    {
        printf("INFO : List is empty\n");
        return FAILURE;
    }

    // Temporary pointer for traversal
    node *temp = head;

    printf("head -> ");

    while(temp != NULL)
    {
        // Print negative sign only for first node
        if(temp == head && result_negative && !(temp->data == 0 && temp->next == NULL))
        {
            printf("-%d ", temp->data);
        }
        else
        {
            printf("%d ", temp->data);
        }

        // Print link symbol between nodes
        if(temp->next != NULL)
        {
            printf("<-> ");
        }

        temp = temp->next;
    }

    printf("<- tail\n");

    return SUCCESS;
    
}

// Function to compare two doubly linked lists
int compare_list(node *head1, node *head2)
{
    int count1 = 0, count2 = 0;
    node *temp1 = head1, *temp2 = head2;

    // Count length of first list
    while (temp1) 
    { 
        count1++; 
        temp1 = temp1->next; 
    }

    // Count length of second list
    while (temp2) 
    { 
        count2++; 
        temp2 = temp2->next; 
    }

    // Compare lengths
    if (count1 > count2) 
    {
        return OPERAND1;
    }
    if (count1 < count2) 
    {
        return OPERAND2;
    }

    // Compare digit by digit
    temp1 = head1;
    temp2 = head2;

    while (temp1 && temp2) 
    {
        if (temp1->data > temp2->data) 
        {
            return OPERAND1;
        }
        if (temp1->data < temp2->data) 
        {
            return OPERAND2;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return SAME; // equal

}

// Function to delete complete list
int delete_list(node **head, node **tail)
{
    // Check empty list
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    node *temp = *head;
   
    // Delete every node
   while(*head != NULL)
   {
       temp = *head;
       
       *head = (*head)->next;
       free(temp);
      
   }
    
   // Reset tail
    *tail = NULL;
    
    return SUCCESS;
}

// Function to remove leading zeros
int remove_pre_zeros(node **head)
{
    // Check empty list
    if(*head == NULL)
    {
        return FAILURE;
    }

    // Remove zeros until one digit remains
    while((*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;

        *head = (*head)->next;
        (*head)->prev = NULL;

        free(temp);
    }

    // ensure single zero node is clean
    if((*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = (*head)->next;

        while(temp != NULL)
        {
            node *del = temp;
            temp = temp->next;
            free(del);
        }

        (*head)->next = NULL;
    }

    return SUCCESS;
}

// Function to find length of list
int list_len(node *head)
{
    
    int count = 0;

    node *temp = head;

    // Traverse list and count nodes
    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    return count;
}

