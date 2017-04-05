/* Shabbir Mahmood  ID: 14015439 Part-3 Even Operating System Lab Best Fit Algorithm Date: 04-04-2017*/
/*
5
400
200
300
500
100
5
10
300
310
550
150
*/
#include<bits/stdc++.h>
using namespace std;

struct Block
{
    int block_id;
    int block_size;
    int internal_fragmentation;
    int block_flag = 0;
};

struct File
{
    int file_id;
    int file_size;
    int file_flag = 0;
};

bool compare(Block lhs, Block rhs) { return lhs.block_size < rhs.block_size; }

int main()
{
    Block block[50];
    File file[50];
    int no_of_block, no_of_file, sum_file=0, sum_block=0;

    cout<<"Enter the no. of Blocks: ";    // Block
    cin>>no_of_block;
    cout<<"Enter Sizes of Each Block:"<<endl;
    for(int i=1; i<=no_of_block; i++)
    {
        cout<<"Block "<<i<<" : ";
        cin>>block[i].block_size;
        block[i].block_id = i;
    }

    cout<<endl;
    cout<<"Enter the no. of Files : ";    // File
    cin>>no_of_file;
    cout<<"Enter Sizes of Each Files:"<<endl;
    for(int i=1; i<=no_of_file; i++)
    {
        cout<<"File "<<i<<" : ";
        cin>>file[i].file_size;
        file[i].file_id = i;
    }
    sort(block+1, block+(no_of_block+1), compare);
    cout<<endl;
    cout<<" FileNO  |  FileSize  |  BlockNo   |   BlockSize  |  InternalFragmentation"<<endl;
    cout<<" -------------------------------------------------------------------------"<<endl;


    for(int i=1; i<=no_of_file; i++)
    {
        for(int j=1; j<=no_of_block; j++)
        {
            if(block[j].block_flag == 0 && file[i].file_size <= block[j].block_size)
            {
                block[j].block_flag = 1;
                file[i].file_flag = 1;
                block[j].internal_fragmentation = block[j].block_size - file[i].file_size;
                printf("  %3d    |    %3d     |    %3d     |     %3d      |         %3d        \n",file[i].file_id,file[i].file_size,block[j].block_id,block[j].block_size,block[j].internal_fragmentation);

                break;

            }

        }
        if(file[i].file_flag == 0)
        {
             printf("  %3d    |    %3d     |     XXX    |     XXX      |         XXX        \n",file[i].file_id,file[i].file_size);
        }
    }
    cout<<" -------------------------------------------------------------------------"<<endl;

    for(int j=1; j<=no_of_block; j++)
    {
        if(block[j].block_flag == 0)
        {
             sum_block += block[j].block_size;
        }

    }
    cout<<"Total Free Space is : "<<sum_block<<endl;
    for(int i=1; i<=no_of_file; i++)
    {
        if(file[i].file_flag == 0 && file[i].file_size <= sum_block)
        {
             cout<<"External Fragmentation has Occurred for File: "<<file[i].file_id<<endl;
             sum_file += file[i].file_size;
        }

    }
    cout<<"Total External Fragmentation is : "<<sum_file<<endl;



    return 0;
}
