/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab Optimal Page Replacement Algorithm Date: 03-04-2017*/
/*
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_pages, no_of_frames, page[100], frame[100], time[100], referencee[100], counter=0, fault=0, maxx, flag1, flag2, flag3 ;
    int position;
    cout<<"Enter the no. of Pages    : ";
    cin>>no_of_pages;
    cout<<"Enter the Reference String: ";
    for(int i=0; i<no_of_pages; i++)
    {
        cin>>page[i];
    }
    cout<<"Enter the no. of Frames   : ";
    cin>>no_of_frames;

    for(int i=0; i<no_of_frames; i++)
    {
        frame[i] = -1;                // Initialize all frames to -1
    }

    cout<<"----------------------------------------------------"<<endl;
    cout<<"(Optimal Page Replacement) Status of Physical Memory"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for(int i=0; i<no_of_pages; i++)
    {
        flag1 = 0;  // Indicates Initial Page Fault
        flag2 = 0;  // Indicates Further Page Fault

        for(int j=0; j<no_of_frames; j++)
        {
            if(frame[j]==page[i])    // (Condition-1-No Page Fault) If the page[i] exists in the physical memory's frame[j] position (j'th position)
            {
                flag1 = flag2 = 1;
                break;              // (1)****
            }
        }

        if(flag1==0)
        {
            for(int j=0; j<no_of_frames; j++)
            {
                if(frame[j] == -1)  // Initial Page Fault
                {
                    frame[j] = page[i]; // Bringing the page[i] into the Physical Memory's frame[j]
                    fault++;        // Incrementing Page fault Counter
                    flag2 = 1;
                    break;       // (2)***

                 }
            }
        }

        if(flag2==0)
        {
           flag3 = 0;
           for(int j=0; j<no_of_frames; j++)
           {
                referencee[j] = -1;

               for(int k=i+1; k<no_of_pages; k++)
               {
                   if(frame[j] == page[k])
                   {
                       referencee[j] = k;
                       break;

                   }
               }
           }

           for(int j=0; j<no_of_frames; j++)
           {
               if(referencee[j] == -1)
               {
                   position = j;
                   flag3 = 1;
                   break;
               }
           }
           if(flag3 == 0) //*********
           {
               maxx = referencee[0];
               position = 0;
               for(int j=1; j<no_of_frames; j++)
               {
                   if(referencee[j]>maxx)
                   {
                       maxx = referencee[j];
                       position = j;
                   }
               }
           }
           frame[position] = page[i];
           fault++;
        }

        // Displaying
        printf("\t"); // Better Look
        for(int j=0; j<no_of_frames; j++)
        {
            if(frame[j]==-1)
            {
                printf(" \t");
                break;
            }
            printf("%d\t",frame[j]);    // Print and tab(\t) ( tab = 4 spaces)
        }
        cout<<endl; //***** Important for next Status Displaying

    }
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<" Total Number of Page Fault is: "<<fault<<endl;
    cout<<"-----------------------------------"<<endl;


    return 0;
}
