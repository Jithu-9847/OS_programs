#include <stdio.h>

int sort_find(int arr[], int n,int num)
{
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            return i;
        }
    }
}

void main()
{
    int no_req,diff,seek=0;

    printf("ENTER THE NUMBER OF BLOCK REQUESTS:");
    scanf("%d",&no_req);
    int seq[++no_req];
    printf("ENTER THE SEQUENCE:");
    for (int i = 1; i < no_req; i++)
    {
        scanf("%d",&seq[i]);
    }
    
    printf("ENTER THE INITIAL HEAD POSITON:");
    scanf("%d",&seq[0]);
    int pos=sort_find(seq,no_req,seq[0]);
   

    for(int i=pos;i<no_req;i++)
    {
        printf("%d->",seq[i]);
    }

    for(int i=pos-1;i>0;i--)
    {
        printf("%d->",seq[i]);
    }
    printf("%d",seq[0]);

    seek+=(seq[no_req-1]-seq[pos]);
    seek+=(seq[no_req-1]-seq[0]);

    printf("\nSEEK TIME:%d",seek);


}