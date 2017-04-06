/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab FIFO Page Replacement Algorithm Date: 06-04-2017*/
/*
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_pages, no_of_frames, page[100], frame[100], fault=0,position=0, flag1, flag2 ;
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
    cout<<"(FIFO) Status of Frames in Physical Memory"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<no_of_pages; i++)
    {
        flag1 = 0;  // Indicates Initial Page Fault
        flag2 = 0;  // Indicates Further Page Fault

        for(int j=0; j<no_of_frames; j++)
        {
            if(frame[j]==page[i])    // (Condition-1-No Page Fault) If the page[i] exists in the physical memory's frame[j] position (j'th position)
            {
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
                    fault++;        // Incrementing Page fault Counter
                    flag2 = 1;
                    break;       // (2)***

                 }
            }
        }

        if(flag2==0)
        {
           frame[position] = page[i]; // Page Replacement
           position++; // FIFO Algorithm *******************
           if(position > (no_of_frames-1))
           {
               position = 0;
           }
           fault++;   // No Break *******
        }

        // Displaying
        printf("\t");
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
