/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab LRU Algorithm Date: 03-04-2017*/
/*
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
#include<bits/stdc++.h>
using namespace std;

int find_free_frame(int time[], int no_of_frames) // Function for Page Replacement using LRU Algorithm
{
    int minimum = time[0],position=0; // ***** Very Important, because the minimum time frame's position is initially 0
    for(int i=1; i<no_of_frames; i++) // Starts from position 1 ***
    {
        if(time[i]<minimum)
        {
            minimum = time[i];
            position = i;
        }
    }
    return position;
}

int main()
{
    int no_of_pages, no_of_frames, page[100], frame[100], time[100], counter=0, fault=0,position, flag1, flag2 ;
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

    cout<<"-----------------------------------------"<<endl;
    cout<<"(LRU) Status of Frames in Physical Memory"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<no_of_pages; i++)
    {
        flag1 = 0;  // Indicates Initial Page Fault
        flag2 = 0;  // Indicates Further Page Fault

        for(int j=0; j<no_of_frames; j++)
        {
            if(frame[j]==page[i])    // (Condition-1-No Page Fault) If the page[i] exists in the physical memory's frame[j] position (j'th position)
            {
                counter++;           // Logical Clock
                time[j] = counter;   // Updating the counter value of fames j'th position
                flag1 = flag2 = 1;   // Page Hit
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
                    counter++;
                    time[j] = counter;
                    fault++;        // Incrementing Page fault Counter
                    flag2 = 1;
                    break;       // (2)***

                 }
            }
        }

        if(flag2==0)
        {
           position = find_free_frame(time,no_of_frames);
           frame[position] = page[i]; // Page Replacement
           counter++;
           time[position] = counter;
           fault++;   // No Break *******
        }

        // Displaying
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
