#include<bits/stdc++.h>
using namespace std;

int time_quantum;
int remain_process;
int total_time;
int counter;
int flag = 0;
double no_of_process;
double sum_waiting_time    = 0;
double sum_turnaround_time = 0;

typedef struct
{
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int arrival_time;
    int remain_burst_time;
} Process;

typedef struct
{
    int process_id;
    int burst_time;
} Process_Show;
Process_Show process_show[100];
int index=1;

void gantt_chart()
{
     cout<<"..........Gantt Chart.........."<<endl;
     cout<<" ";                       // Top Line
    for( int i=1; i<=index; i++)
    {
        for(int j=1; j<=process_show[i].burst_time; j++)
        {
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<"\n|";

    for( int i=1; i<index; i++)
    {
        for(int j=1; j<=(process_show[i].burst_time/2); j++)
        {
            cout<<" ";
        }
        cout<<process_show[i].process_id;
        if( process_show[i].burst_time%2==0) // Checking Odd or Even Burst time
        {
           for(int j=1; j<=(process_show[i].burst_time/2)-1; j++)
            {
                cout<<" ";
            }
        }
        else
        {
            for(int j=1; j<=(process_show[i].burst_time/2); j++)
            {
                cout<<" ";
            }
        }
        cout<<"|";
    }
    cout<<endl;
    cout<<" ";               // Bottom line
    for( int i=1; i<index; i++)
    {
        for(int j=1; j<=process_show[i].burst_time; j++)
        {
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<endl;
    cout<<"0";
    int s=0;
    for( int i=1; i<=index-1; i++)
    {

        for(int j=1; j<=process_show[i].burst_time; j++)
        {
            cout<<" ";
        }

        s=s+process_show[i].burst_time;
        if( s> 9) printf("\b");//************* Consume One Space Bar
        cout<<s;
    }
    cout<<endl;
}
void calculate(Process process[],int no_of_process)
{
    for(total_time=0,counter=1; remain_process!=0;   )
    {
        if(process[counter].remain_burst_time <= time_quantum && process[counter].remain_burst_time>0 )
        {
            total_time +=  process[counter].remain_burst_time;
            //////////////////////
            process_show[index].burst_time = process[counter].remain_burst_time;
            process_show[index].process_id =  process[counter].process_id;
            index++;
            //////////////////////
            process[counter].remain_burst_time = 0;
            flag = 1;

        }
        else if(process[counter].remain_burst_time > 0)
        {
            process[counter].remain_burst_time -= time_quantum;
            total_time += time_quantum;
            //////////////////////
            process_show[index].burst_time = time_quantum;
            process_show[index].process_id =  process[counter].process_id;
            index++;
            //////////////////////
        }
        if(process[counter].remain_burst_time == 0 && flag == 1)
        {
            remain_process--;

            process[counter].waiting_time = total_time -  process[counter].burst_time;
            process[counter].turnaround_time = total_time;

            sum_waiting_time += total_time -  process[counter].burst_time;
            sum_turnaround_time += total_time;
            flag = 0;//************
        }
        if(counter == no_of_process)
        {
            counter = 1;
        }
        else if(0<=total_time)
        {
            counter++;
        }
        else
        {
            counter = 1;
        }
    }
}


void show(Process process[],int no_of_process)
{
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
   /* for( int i=1; i<=no_of_process; i++)
    {
        sum_waiting_time = sum_waiting_time + process[i].waiting_time;
    }
     for( int i=1; i<=no_of_process; i++)
    {
        sum_turnaround_time = sum_turnaround_time + process[i].turnaround_time;
    }*/

    cout<<"Average Waiting Time  : "<<(sum_waiting_time/no_of_process)<<endl;
    cout<<"Average Turnround Time: "<<(sum_turnaround_time/no_of_process)<<endl;
}

int main()
{
    Process process[100];
    cout<<"Enter the total number of process: ";
    cin>>no_of_process;
    remain_process = no_of_process;//**************
    cout<<"Enter the Burst Time of each individual process:"<<endl;

    for(int i=1; i<=no_of_process; i++)
    {
        cout<<"P"<<i<<" : ";
        cin>>process[i].burst_time;
        process[i].remain_burst_time = process[i].burst_time;//*************
        process[i].process_id        = i;
    }
    /*cout<<"Enter the arrival time of each process: ";
    for(int i=1; i<=no_of_process; i++)
    {
        cout<<"P"<<i<<" : ";
        cin>>process[i].arrival_time;
    }*/

    cout<<"Enter the time Quantum: ";
    cin>>time_quantum;

    calculate(process,no_of_process);
    show(process,no_of_process);
    gantt_chart();


    return 0;
}

