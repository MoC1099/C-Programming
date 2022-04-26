#include <stdio.h>
#include <cs50.h>

// program will take a user input for height and output a payramid with a gap in between.
void payramid(int height);

int main()
{
    int height;
    do
    {
        //Get the Height
        height = get_int("Enter the height: ");
    }
    while (height <= 0 || height > 8);
    // If height betwen 1-9 make a payramid
    if (height > 0 && height < 9)
    {
        payramid(height);
    }
}
void payramid(int height)
{
    int k = height;
    for (int y = 1; y <= height; y++)
    {
        // for the spaces
        for (int x = k; x > 1; x--)
    {
        printf(" ");
    }
    k--;

       // for left #'s
       for (int i = 0; i < y; i++)
       {
           printf("#");
       }
     printf(" "" ");

        // for right #'s
       for (int i = 0; i < y; i++)
       {
           printf("#");
       }
       printf("\n");
    }
}