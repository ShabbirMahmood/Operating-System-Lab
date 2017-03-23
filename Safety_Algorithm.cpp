/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab Safety Algorithm (Banker Algorithm) Algorithm Date: 02-02-2017*/
#include<bits/stdc++.h>
using namespace std;

    int no_resource,no_process;
    int instance_vector[100];
    int allocation[100][100];
    int maxx[100][100];
    int need[100][100];
    int available[100];

    bool finish[100];
    int work[100];
    int cc=0,c=0,cnt=0;
    int x=0;
    int safe_sequence[50];

int check_finish()                          // Checking Finish[i] = true for all i
{
     c=0;//*************
     for(int i=0; i<no_process; i++)
     {
         if(finish[i] == true)
         {
             c++;
         }
     }
     if (c==no_process)
     {
         return 1;
     }
     return 0;
}
int compare_need_work(int p) // Checking Need[i] <= Work[i]
    {
        int cnt=0;//*************************
        for(int i=0; i<no_resource; i++)
        {
            if(need[p][i] <= work[i])
            {
                cnt++;
            }
        }
        if(cnt==no_resource)
        {
            return 1;
        }
        else
            return 0;
}

int safety_algorithm()                // Safety Algorithm
{
    for(int i=0; i<no_process; i++)
    {
        finish[i] = false;
    }
    for(int i=0; i<no_resource; i++)
    {
       work[i] = available[i];
    }




TOP:  for(int i=0; i<no_process; i++)
       {
           if(finish[i]== false && compare_need_work(i))
            {
                for(int j=0; j<no_resource; j++)
                {
                   work[j] += allocation[i][j];
                }
                finish[i] =true;
                //cnt++;
                safe_sequence[x++] = i;

            }
       }
       if(check_finish())
       {
            return 1;             // Finish[i] is true for all i, Complete
       }
       else if(cc<no_process)
       {
            cc++;
            goto TOP;             // Goto the top label, But it will repeat up to no_process number

       }
       else
       {
           return 0;            // Deadlock Occur
       }


}

int main()
{
    cout<<"Enter the No. of Resources: ";
    cin>>no_resource;
    cout<<"Enter the No. of Instances of Resource Vector: "<<endl;
    for(int i=0; i<no_resource; i++)
    {
        cout<<"R"<<i<<": ";
        cin>>instance_vector[i];
    }
    cout<<"Enter the No. of Processes: ";
    cin>>no_process;
    cout<<"Enter the Allocation Matrix: "<<endl;

    for(int i=0; i<no_process; i++)
    {
        for(int j=0; j<no_resource; j++)
        {
            cin>>allocation[i][j];
        }
    }
    cout<<"Enter the Max Matrix: "<<endl;

    for(int i=0; i<no_process; i++)
    {
        for(int j=0; j<no_resource; j++)
        {
            cin>>maxx[i][j];
        }
    }
    cout<<"The Available Instance Vector is: "<<endl;
    for(int j=0; j<no_resource; j++)
    {
        for(int i=0; i<no_process; i++)
        {
             available[j] += allocation[i][j];

        }
        available[j] = instance_vector[j] - available[j];
        cout<<available[j]<<" ";

    }
    cout<<endl;


    cout<<"The Need Matrix is: "<<endl;

    for(int i=0; i<no_process; i++)
    {
        for(int j=0; j<no_resource; j++)
        {
            need[i][j] = maxx[i][j] - allocation[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }

    if(safety_algorithm())    // if this function return 1 then Safe Sequence Exits
    {
        cout<<"There is a Safe Sequence & the Sequence is: ";
        for(int i=0; i<no_process; i++)
        {
            cout<<"P"<<safe_sequence[i]<<" ";
        }
    }
    else                  // if this function return 0 then Safe Sequence does not Exit (Deadlock)
    {
        cout<<"No Safe Sequence(Deadlock)"<<endl;
    }
    cout<<endl;

    return 0;
}
