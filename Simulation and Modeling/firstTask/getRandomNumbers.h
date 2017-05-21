#include<iostream>
#include<cstdlib>

int *getRandomNumbers(int minimum, int maximum, int limit)
{
    int *arry = new int[limit + 1];
    int i=0 , randomNumber=0 , range=0;

    range = maximum - minimum;

    for(i=1; i<=limit; i++)
    {
        randomNumber = (rand() % (range + 1)) + minimum;

        arry[i] = randomNumber;
    }

    return arry;
}
