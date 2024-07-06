#include<stdio.h>

void fifo(int sq[],int n,int f_no)
{
    int frame[f_no],fifo[f_no],counter=0,hit=0;

    for(int i=0;i<f_no;i++)frame[i]=-1;

    for(int i=0;i<n;i++)
    {
        if(counter<3)
        {
            frame[counter]=sq[i];
            fifo[counter]=++counter;
        }
        else
        {
            int small=fifo[0],index=0,flag=0;

            for(int j=0;j<f_no;j++)
            {
                if(sq[i]==frame[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                for(int j=1;j<f_no;j++)
            {
                if(fifo[j]<small)
                {
                    small=fifo[j];
                    index=j;
                }

            }
            frame[index]=sq[i];
            fifo[index]=++counter;
            }
            else{
                hit++;
            }
            
        }
         for(int j=0;j<f_no;j++)
         {
            if(frame[j]==-1)
            {
                printf(" \t");
            }
            else{
                printf("%d\t",frame[j]);
            }
         }
         printf("\n");
    }
    printf("MISS RATIO=%f\n",(float)((n-hit)/n));
    printf("HIT RATIO=%f\n",(float)(hit/n));


}

int find_lru(int frame[],int f_no)
{
    int min,index;
    min=frame[0];
    index=0;
    for(int i=1;i<f_no;i++)
    {
        if(frame[i]<min)
        {
            min=frame[i];
            index=i;
        }
    }
    return index;
}

void lru(int sq[],int n,int f_no)
{
    int frame[f_no],counter=0,hit=0,time[f_no];

    for(int i=0;i<f_no;i++)frame[i]=-1;

    for(int i=0;i<n;i++)
    {
        int flag1=0,flag2=0;

         for(int j=0;j<f_no;j++)
         {
            if(frame[j]==sq[i])
            {
                counter++;
                hit++;
                time[j]=counter;
                flag1=flag2=1;
                break;
            }
         }

         
             if(flag1==0)
            {
                for(int j=0;j<f_no;j++){
                if(frame[j]==-1)
                {
                    counter++;
                    time[j]=counter;
                    frame[j]=sq[i];
                    flag2=1;
                    break;
                }
            }
    }
            if(flag2==0){

                int index=find_lru(time,f_no);
                counter++;
                frame[index]=sq[i];
                time[index]=counter;
            }
         

         for(int j=0;j<f_no;j++)
         {
            if(frame[j]==-1)
            {
                printf(" \t");
            }
            else{
                printf("%d\t",frame[j]);
            }
         }
         printf("\n");
    }
    printf("MISS RATIO=%f\n",((float)(n-hit)/n));
    printf("HIT RATIO=%f\n",(float)hit/n);


}

void main()
{
    int n,f_no;

    printf("ENTER THE NUMBER OF PAGES:");
    scanf("%d",&n);
    int sq[n];
    printf("ENTER THE PAGES:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&sq[i]);
    }
    printf("ENTER THE NUMBER OF FRAMES:");
    scanf("%d",&f_no);

    lru(sq,n,f_no);
}