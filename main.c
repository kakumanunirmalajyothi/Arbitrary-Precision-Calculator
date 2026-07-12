/*

    NAME                 : K.NIRMALA JYOTHI
    REG NO               : 25048_037
    SUBMISSION DATE      : 26-6-26

    DESCRIPTION:

    1. main()

    Purpose:
    Main control function of APC calculator. It handles input validation, operand conversion, 
    operation selection, sign handling, and result printing.

    Working:

        Initializes linked list pointers for two operands and result.
        Initializes global variable result_negative to store result sign.
        Validates command line arguments using cla_validation().
        Checks the signs of both operands.
        Converts operands from string format into doubly linked lists using create_list().
        Removes leading zeros using remove_pre_zeros().
        Prints input lists.
        Performs operation based on operator:
        Addition (+)
        Subtraction (-)
        Multiplication (x)
        Division (/)
        Handles positive and negative number combinations.
        Calls respective arithmetic functions.
        Prints final result.
        Validation and List Creation Functions
        
    2. cla_validation()

    Prototype:

        int cla_validation(int argc, char *argv[])

    Purpose:
        Validates command line arguments before performing calculations.

    Working:

        Checks whether arguments are provided.
        Checks number of arguments.
        Validates operator.
        Allows only:
        +
        -
        x
        /
        Displays error message for invalid input.
        Returns:
        SUCCESS if valid.
        FAILURE if invalid.

    3. create_list()

    Prototype:

        void create_list(char *opr, node **head, node **tail)

    Purpose:
        Converts a number string into a doubly linked list.

    Working:

        Traverses each character of operand.
        Skips sign characters (+ and -).
        Converts character digit into integer.
        Inserts each digit at the end of the list.
        Example:
        Input:
        1234
        Linked list:
        1 <-> 2 <-> 3 <-> 4

    4. insert_first()

    Prototype:

        int insert_first(node **head,node **tail,int data)

    Purpose:
        Inserts a new node at the beginning of doubly linked list.

    Working:

        Creates a new node.
        Stores given data.
        If list is empty:
        New node becomes head and tail.
        Otherwise:
        Connects new node before existing head.
        Updates head pointer.

        Example:

        Before:

        2 <-> 3

        Insert 1:

        After:

        1 <-> 2 <-> 3

    5. insert_last()

    Prototype:

        int insert_last(node **head,node **tail,int data)

    Purpose:
        Adds a node at the end of the list.

    Working:

        Creates a new node.
        If list is empty:
        New node becomes head and tail.
        Otherwise:
        Connects new node after tail.
        Updates tail pointer.

        Example:

        Before:

        1 <-> 2

        Insert 3:

        After:

        1 <-> 2 <-> 3

    6. print_list()

    Prototype:

        int print_list(node *head)

    Purpose:
        Displays linked list elements.

    Working:

        Checks whether list is empty.
        Traverses from head to tail.
        Prints:
        Negative sign if result is negative.
        Each digit.
        Link representation.

        Example:

        head -> 1 <-> 2 <-> 3 <- tail

    7. delete_list()

    Prototype:

        int delete_list(node **head,node **tail)

    Purpose:
        Deletes complete linked list and frees memory.

    Working:

        Traverses from head.
        Frees every node.
        Sets head and tail to NULL.

        Used to avoid memory leaks.

    8. remove_pre_zeros()

    Prototype:

        int remove_pre_zeros(node **head)

    Purpose:
        Removes unnecessary zeros before a number.

    Example:

        Before:

        0 0 0 5

        After:

        5

        Working:

        Removes zero nodes from beginning.
        Keeps single zero for number 0.
        Adjusts head pointer.

    9. compare_list()

    Prototype:

        int compare_list(node *head1,node *head2)

    Purpose:
        Compares two numbers stored in linked lists.

    Working:

        Finds length of both lists.
        Longer list represents larger number.
        If lengths equal:
        Compares digit by digit.

        Returns:

        OPERAND1  -> first number bigger
        OPERAND2  -> second number bigger
        SAME      -> equal

        Example:

        123 > 45

        returns:

        OPERAND1

    10. list_len()

    Prototype:

        int list_len(node *head)

    Purpose:
        Finds number of nodes in linked list.

    Working:

        Traverses list.
        Increments count for every node.
        Returns length.

        Example:

        1 <-> 2 <-> 3

        Length = 3

        Arithmetic Functions
    11. addition()

    Prototype:

        void addition(node *head1,node *tail1,node *head2,node *tail2,
        node **headR,node **tailR,char sign1,char sign2)

    Purpose:
        Adds two large numbers using doubly linked list.

    Working:

        Starts addition from tail because digits are stored normally.
        Adds corresponding digits.
        Handles carry.
        Stores result from beginning using insert_first().

        Example:

        999
        +   1
        -----
        1000

        Handles:

        Positive + positive
        Negative + negative
        Positive + negative
        Negative + positive

    12. subtraction()

    Prototype:

        void subtraction(node *tail1,node *tail2,
        node **headR,node **tailR)

    Purpose:
        Subtracts two numbers.

    Working:

        Starts subtraction from tail.
        Performs digit subtraction.
        Handles borrow.
        Stores result.
        Removes leading zeros.

        Example:

        500
        -200
        ----
        300

    13. multiplication()

    Prototype:

        void multiplication(node *tail1,node *tail2,
        node **headR,node **tailR)

    Purpose:
        Multiplies two large numbers.

    Working:

        Uses digit-by-digit multiplication.
        Multiplies each digit of second number with first number.
        Creates partial results.
        Adds partial results.
        Handles carry.
        Adds zeros according to position.

        Example:

        123
        *  2
        ----
        246

    14. division()

    Prototype:

        int division(node *head1,node *head2,
        node **headR,node **tailR)

    Purpose:
        Performs division operation.

    Working:

        Checks invalid lists.
        Checks division by zero.
        Uses repeated subtraction method.

        Example:

        10 / 2

        Process:

        10-2 = 8
        8-2 = 6
        6-2 = 4
        4-2 = 2
        2-2 = 0

        Count = 5

        Result:

        5
*/


#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    // global flag to indicate result sign
    result_negative = 0;

    // validate command line arguments
	if(cla_validation(argc, argv) == FAILURE)
    {
        return FAILURE;
    }

    char sign1 = '+';   // assume number1 is positive
    char sign2 = '+';   // assume number2 is positive


    // check if first number is negative
    if(argv[1][0] == '-')
    {
        sign1 = '-';
    }

    // check if second number is negative
    if(argv[3][0] == '-')
    {
        sign2 = '-';
    }

    // convert first string number into linked list
    create_list(argv[1], &head1, &tail1);
    // convert second string number into linked list
    create_list(argv[3], &head2, &tail2);

    // Remove leading zeros from both lists
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);


    printf("List 1 : ");
    print_list(head1);

    printf("List 2 : ");
    print_list(head2);

    // operator (+, -, x, /)
    char oper = argv[2][0];

    switch(oper)
    {
        case '+':

            printf("Result : ");
            result_negative = 0;

            // case: (-) + (-)
            if(sign1 == '-' && sign2 == '-')
            {
                result_negative = 1;
                addition(head1, tail1, head2, tail2, &headR, &tailR, '+', '+');
            }
            // case: (+) + (-)
            else if(sign1 == '+' && sign2 == '-')
            {

                if(compare_list(head1, head2) == OPERAND1 || compare_list(head1, head2) == SAME)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    result_negative = 0;
                }

                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    result_negative = 1;
                }
            }
            // case: (-) + (+)
            else if(sign1 == '-' && sign2 == '+')
            {

                if(compare_list(head1, head2) == OPERAND1 || compare_list(head1, head2) == SAME)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    result_negative = 1;
                }

                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    result_negative = 0;
                }
            }
            else
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR, '+', '+');
            }

            print_list(headR);

        break;

        case '-':

            printf("Result : ");
            result_negative = 0;

            // (-) - (+)  => -(a+b)
            // Example: -5 - 2 = -7
            if(sign1 == '-' && sign2 == '+')
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR, '+', '+');

                result_negative = 1;
            }

            // (+) - (-)  => a+b
            // Example: 5 - (-2) = 7
            else if(sign1 == '+' && sign2 == '-')
            {
                addition(head1, tail1, head2, tail2, &headR, &tailR, '+', '+');
            }

            // (+) - (+)
            else if(sign1 == '+' && sign2 == '+')
            {
                if(compare_list(head1, head2) == OPERAND1 || compare_list(head1, head2) == SAME)
                {
                    subtraction(tail1, tail2, &headR, &tailR);
                }
                else
                {
                    result_negative = 1;

                    subtraction(tail2, tail1, &headR, &tailR);
                }
            }

            // (-) - (-)
            // Example: -5 - (-2) = -3
            else if(sign1 == '-' && sign2 == '-')
            {
                if(compare_list(head1, head2) == OPERAND1 || compare_list(head1, head2) == SAME)
                {
                    subtraction(tail1, tail2, &headR, &tailR);
                    result_negative = 1;   
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);
                    result_negative = 0;   
                }
            }

            print_list(headR);

        break;

        case 'x':
        case 'X':

            multiplication(tail1, tail2, &headR, &tailR);
            printf("Result : ");

            // if signs are different, result is negative
            if((sign1 == '+' && sign2 == '-') || (sign1 == '-' && sign2 == '+'))
            {
                result_negative = 1;
            }
            else
            {
                result_negative = 0;
            }
            print_list(headR);
            
        break;

        case '/':
            division(head1, head2, &headR, &tailR);

            // if division by zero happened, stop execution
            if(headR == NULL)
            {
                // "Division by zero not possible"
                break;
            }
            printf("Result : ");

            // sign handling for division
            if((sign1 == '+' && sign2 == '-') || (sign1 == '-' && sign2 == '+'))
            {
                result_negative = 1;
            }
            else
            {
                result_negative = 0;
            }

            print_list(headR);
        break;

        default:
            printf("Invalid operator\n");
    }
}

