
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
    // declaring variables to be used
    long CCnum;
    char str[21];
    int length;
    int array[2];
    int checkSUM = 0 ;

    int first_digit = 0;
    int second_digit = 0;



    //loop to propmt for user ccredit card number
    //reprompts when its a negative number and breaks program when length is invalid
    do
    {
        CCnum = get_long("Number: ");
        length = sprintf(str, "%li", CCnum);
    }
    while (CCnum < 0);


    //parent loop going
    for (int i = 0 ; i < length ; i++)
    {
        int current_num = CCnum % 10;
        CCnum = CCnum / 10;




        // if condition checking for numbers second to last digit
        if (i % 2 != 0)
        {
            int MultipliedAns = (current_num * 2);
            if (MultipliedAns >= 10)
            {
                // neted loop which checks if current number is double and seperated them in order to satisfy formula
                for (int l = 0 ; l < 2 ; l++)
                {
                    array[l] = MultipliedAns % 10;
                    checkSUM  = checkSUM + array[l];
                    MultipliedAns = (MultipliedAns / 10);
                }
            }
            else
            {
                checkSUM = checkSUM + MultipliedAns;
            }


        }


        // if cndition checking for numbers not second to last digit
        if (i % 2 == 0)
        {
            checkSUM = checkSUM + current_num;
        }


        //gettling fist and second digiit
        if (i == length - 1)
        {
            first_digit = first_digit + current_num;
        }

        if (i == length - 2)
        {
            second_digit = second_digit + current_num;
        }

    }

    //if conditions checking for credit validality and type

    if (checkSUM % 10 == 0)
    {
        printf ("VALID\n");
    }
    if (checkSUM % 10 != 0  || length < 13)
    {
        printf("INVALID\n");
    }

    if (checkSUM % 10 == 0 && first_digit == 4  &&  length >= 13)
    {
        printf("VISA\n");
    }



    if (checkSUM % 10 == 0 && first_digit == 5 && second_digit <= 5)
    {
        printf("MASTERCARD\n");
    }
    else if (checkSUM % 10 == 0 && first_digit == 5 && second_digit > 5)
    {
        printf("INVALID\n");
    }



    if ((checkSUM % 10 == 0 && first_digit == 3) && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
    }
    else if (checkSUM % 10 == 0 && first_digit == 3  && (second_digit != 4 && second_digit != 7))
    {
        printf("INVALID\n");
    }


}

