#include<stdio.h>

void main()
{
    int r,p,i,j,k,y;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d",&p);
    printf("ENTER THE NUMBER OF RESOURSES:");
    scanf("%d",&r);

    int alloc[p][r],max[p][r],need[p][r],avail[r];

    printf("ENTER THE ALLOCATION MATRIX:");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("ENTER THE MAX MATRIX:");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("ENTER THE AVAILABLE MATRIX:");
     
        for(j=0;j<r;j++)
        {
            scanf("%d",&avail[j]);
        }
     
     int f[p],ans[p],ind=0;

     for(int i=0;i<p;i++)
     { f[i]=0;}
       

    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

for(k=0;k<p;k++)
{
    for(i=0;i<p;i++)
    {
        if(f[i]==0)
        {
            int flag=0;
            for(j=0;j<r;j++)
            {
             if(need[i][j]>avail[j])
             {
                flag=1;
                break;
             }
              
            }

            if(flag==0)
            {
                ans[ind++]=i;
                for(y=0;y<r;y++)
                {
                    avail[y]+=alloc[i][y];
                }
                f[i]=1;
            }
        }
        
    }
}  

int flag=0;

for(i=0;i<p;i++)
{
    if(f[i]==0)
    {
        flag=1;
        break;
    }
     
}

if (flag == 0) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < p - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[p - 1]);
    }
else{
     printf("NOT SAFE STATE!");
}
}