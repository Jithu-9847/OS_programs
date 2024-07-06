#include<stdio.h>
#include<stdlib.h>
void main(){
    int no_req,diff,seek=0;

    printf("ENTER THE NUMBER OF BLOCK REQUESTS:");
    scanf("%d",&no_req);
    int seq[no_req+1];
    printf("ENTER THE SEQUENCE:");
    for (int i = 1; i <= no_req; i++)
    {
        scanf("%d",&seq[i]);
    }
    
    printf("ENTER THE INITIAL HEAD POSITON:");
    scanf("%d",&seq[0]);

    for(int i=0;i<no_req;i++)
    {
        diff=abs(seq[i+1]-seq[i]);
        seek+=diff;
        printf("%d->",seq[i]);
    }
    printf("%d",seq[no_req]);
    printf("\nSEEK TIME=%d",seek);

}