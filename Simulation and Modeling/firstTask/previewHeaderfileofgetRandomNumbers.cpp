#include<iostream>
#include<cstdlib>
#include"getRandomNumbers.h"
using namespace std;

int main()
{
    int *ptr = getRandomNumbers(5 , 10 , 100);

    for(int i=1; i<=100; i++) cout << ptr[i] << "; ";

    return 0;
}
