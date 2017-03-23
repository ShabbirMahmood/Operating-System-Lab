/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab SJF Algorithm Date: 11-02-2017*/
#include<bits/stdc++.h>
using namespace std;

int no_of_process;
double sum_waiting_time    = 0;
double sum_turnaround_time = 0;

typedef struct
{
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int priority;
} Process;
bool compare(Process lhs, Process rhs) { return lhs.priority < rhs.priority; }//Sorting Function

void gantt_chart(Process process[],int no_of_process)
{
     cout<<"..........Gantt Chart.........."<<endl;
     cout<<" ";                       // Top Line
    for( int i=1; i<=no_of_process; i++)
    {
        for(int j=1; j<=process[i].burst_time; j++)
        {
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<"\n|";

    for( int i=1; i<=no_of_process; i++)
    {
        for(int j=1; j<=(process[i].burst_time/2); j++)
        {
            cout<<" ";
        }
        cout<<process[i].process_id;
        if( process[i].burst_time%2==0) // Checking Odd or Even Burst time
        {
           for(int j=1; j<=(process[i].burst_time/2)-1; j++)
            {
                cout<<" ";
            }
        }
        else
        {
            for(int j=1; j<=(process[i].burst_time/2); j++)
            {
                cout<<" ";
            }
        }
        cout<<"|";
    }
    cout<<endl;
    cout<<" ";               // Bottom line
    for( int i=1; i<=no_of_process; i++)
    {
        for(int j=1; j<=process[i].burst_time; j++)
        {
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<endl;
    cout<<"0";
    for( int i=1; i<=no_of_process; i++)
    {
        for(int j=1; j<=process[i].burst_time; j++)
        {
            cout<<" ";
        }
        if(process[i].turnaround_time > 9) printf("\b");//************* Consume One Space Bar
        cout<<process[i].turnaround_time;
    }
    cout<<endl;


}

void calculate(Process process[],int no_of_process)
{
    process[0].waiting_time = 0;
    process[0].burst_time   = 0;
    double sum = 0;
    for( int i=1; i<=no_of_process; i++)
    {
        sum  = sum + process[i-1].burst_time;
        process[i].waiting_time = sum;
    }

    process[0].turnaround_time = 0;
    sum = 0;
    for( int i=1; i<=no_of_process; i++)
    {
        process[i].turnaround_time = process[i].waiting_time   + process[i].burst_time;
    }
    cout<<"Assuming all the processes arrives at time 0"<<endl;
    cout<<" ----------------------------------------------------------"<<endl;
    cout<<"| Process ID | Burst Time | Waiting Time | Turnaround Time |"<<endl;
    cout<<" ---------------------------------------------------------- "<<endl;
    for( int i=1; i<=no_of_process; i++)
    {
        printf("|    %3d     |     %3d    |      %3d     |      %3d        |\n"
           , process[i].process_id, process[i].burst_time,process[i].waiting_time,process[i].turnaround_time);
    }
    cout<<" ---------------------------------------------------------- "<<endl;
    for( int i=1; i<=no_of_process; i++)
    {
        sum_waiting_time = sum_waiting_time + process[i].waiting_time;
    }
     for( int i=1; i<=no_of_process; i++)
    {
        sum_turnaround_time = sum_turnaround_time + process[i].turnaround_time;
    }

    cout<<"Average Waiting Time  : "<<(sum_waiting_time/no_of_process)<<endl;
    cout<<"Average Turnround Time: "<<(sum_turnaround_time/no_of_process)<<endl;
}

int main()
{
    Process process[100];
    cout<<"Enter the total number of process: ";
    cin>>no_of_process;
     cout<<"Enter the Burst Time & Priority of each individual process:"<<endl;;

    for(int i=1; i<=no_of_process; i++)
    {
        cout<<"P"<<i<<" : ";
        cin>>process[i].burst_time;
        cout<<"P"<<i<<" Priority: ";

        cin>>process[i].priority;
        process[i].process_id = i;
    }

    sort(process+1, process+(no_of_process+1), compare);

    calculate(process,no_of_process);
    gantt_chart(process,no_of_process);



    return 0;
}
/*
5
10 3
1 1
2 4
1 5
5 2

*/
