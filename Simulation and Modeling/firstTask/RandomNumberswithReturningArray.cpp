#include<iostream>
#include<cstdlib>
using namespace std;

// formula

// RandomNumber = (rand() % (range + 1)) + min; where, range = max - min;

// dynamic allocated memory

int *fun(int a , int b)
{
    int *arr = new int[2];

    arr[0] = a + b;
    arr[1] = b - a;

    return arr;
}


int *generateRandom(int mn , int mx , int limit)
{
    int *arr = new int[limit+1];

    int i=0 , num=0;

    // num = rand() % (range + 1) + min;

    int range = mx - mn;

    for(i=1; i<=limit; i++)
    {
        num = (rand() % (range + 1)) + mn;

        arr[i] = num;
    }

    return arr;
}

int main()
{
    int *ptr = generateRandom(5, 10, 100);

    for(int i=1; i<=100; i++) cout << ptr[i] << "; ";

    return 0;
}
