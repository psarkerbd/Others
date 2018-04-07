#include<bits/stdc++.h>
using namespace std;

const int high = 1e3+3;
const int inf = 1e8+5;

struct sample
{
    int burst, arrival;
}arr[high];

struct guntt
{
    int process , start , end;
}brr[high];

int flag[high];
int waiting = 0 , total_time = 0 , i , j , mini , diff, k , num , indx;
int len = 0 , fl = 0 , curr = 0;

void find_minimum(int par)
{
    mini = inf;

    if(par == 0)
    {
        for(int i=0; i<curr+2; i++)
        {
            if(mini > arr[i].burst)
            {
                mini = arr[i].burst;
                indx = i;
            }
        }
    }

    else
    {
        for(int i=0; i<num; i++)
        {
            if(mini > arr[i].burst)
            {
                mini = arr[i].burst;
                indx = i;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> num;

    for(i=0; i<num; i++)
    {
        cin >> arr[i].arrival >> arr[i].burst;

        total_time += arr[i].burst;
    }

    cout << total_time << "\n";

    //return 0;

    while(waiting != total_time)
    {
        flag[curr]+=1;

        brr[len].process = curr;
        brr[len].start = waiting;

        if(flag[curr] == 1 && fl == 0)
        {
            diff = arr[curr+1].arrival - arr[curr].arrival;

            find_minimum(0);

            if(curr != indx)
            {
                waiting += diff;
                arr[curr].burst -= diff;
                brr[len].end = waiting;
                len+=1;
            }

            curr = indx;
        }

        else
        {
            fl = 1;
            waiting += arr[curr].burst;
            arr[curr].burst = inf;
            brr[len].end = waiting;
            len+=1;

            mini = inf;
            find_minimum(1);
            curr = indx;
        }
    }

    for(i=0; i<len; i++)
    {
        cout << brr[i].process << " " << brr[i].start << " " << brr[i].end << "\n";
    }

    return 0;
}
