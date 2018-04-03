#include<bits/stdc++.h>
using namespace std;

typedef vector<int>vii;

const int high = 1e3+3;

struct info
{
    int process;
    int start , end;
};

info arr[high];

struct db
{
    int start , end;
    db(int s , int e)
    {
        start = s;
        end = e;
    }
};

vector<int>adj[high];

int burst[high] , len=0, calculate[high] , flag[high] , brst[high];

void Round_Robin_without_Arrival(int time_quantum , int indx , int num)
{
    int split =0, waiting = 0 , i=0;

    while(burst[indx] > 0)
    {
        if(burst[i] > 0)
        {
            arr[len].start = waiting;
            split = burst[i] - time_quantum;
            if(burst[i] > time_quantum) waiting += time_quantum;
            else waiting += burst[i];
            burst[i] = split;
            //cout << waiting << "; ";
            arr[len].end = waiting;
            arr[len].process = i+1;
            len++;
        }

        if(i == num) i=0;
        else i++;
    }
}

int main()
{
    int num , i;
    cout << "Enter Number of Process: ";
    cin >> num;

    int maxi = -1 , indx = 0;

    cout << "Enter Burst times: ";

    for(i=0; i<num; i++)
    {
        cin >> burst[i];
        brst[i] = burst[i];

        if(maxi < burst[i])
        {
            maxi = burst[i];
            indx = i;
        }
    }

    int time_quantum , split;

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    Round_Robin_without_Arrival(time_quantum , indx , num);

    cout << "\n\t------Result-----\n";

    //cout << "\nProcess\tWaiting time\t" << "Process\n";

    for(i=0; i<len; i++)
    {
        cout << " " << arr[i].process << " " << arr[i].start << " " << arr[i].end << "\n";
    }

    int j , calculate[high];

    for(i=1; i<=num; i++)
    {
        int curr = i;

        for(j=0; j<len; j++)
        {
            if(curr == arr[j].process)
            {
                int s = arr[j].start;
                int e = arr[j].end;

                adj[curr].push_back(s);
                adj[curr].push_back(e);

                calculate[curr] = adj[curr][0];
            }
        }
    }

    for(i=1; i<=num; i++)
    {
        for(j=1; j<adj[i].size()-1; j+=2)
        {
            if(j > 0)
            {
                int x = adj[i][j];
                int y = adj[i][j+1];

                //cout << "x = " << x << " y = " << y << "\n";

                calculate[i] = calculate[i] + (y - x);
            }
        }
    }

    double avgWaiting = 0.0, turn = 0.0;

    for(i=1; i<=num; i++)
    {
        //cout << calculate[i] << "; ";
        avgWaiting += (calculate[i] * 1.0);
    }

    avgWaiting /= (num * 1.0);

    cout << "Average Waiting Time: " << avgWaiting << "\n";

    for(i=1; i<=num; i++)
    {
        turn += ((brst[i-1] + calculate[i]) * 1.0);
    }

    cout << "Turn Around Time: " << turn << "\n";

    double avgTurn = turn / (num * 1.0);

    cout << "Average Turn Around Time: " << avgTurn << "\n";

    return 0;
}
