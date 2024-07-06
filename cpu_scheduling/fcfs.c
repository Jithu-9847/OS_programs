#include<stdio.h>

//-------------------FCFS CODE-----------------
void fcfs(int at[],int bt[],int n)
{
	int p[n],index=0;
for(int j=0;j<n;j++)p[j]=j;

	int ct[n],tat[n],wt[n],temp=0,i,avg_tat=0,avg_wt=0;
for(int j=0;j<n;j++)
{
	for(i=1;i<n;i++)
	{
		 if(at[i-1]>at[i])
		 {
			int swap=at[i-1];
			at[i-1]=at[i];
			at[i]=swap;

			swap= bt[i-1];
			 bt[i-1]= bt[i];
			 bt[i]=swap;

			  swap=  p[i-1];
			  p[i-1]=  p[i];
			  p[i]=swap;
		 }
		  
	}
	
}
	
	for(i=0;i<n;i++)
	{
		temp+=bt[i];
		ct[i]=temp;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	
	printf("P\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
		avg_tat+=tat[i];
		avg_wt+=wt[i];
	}
	printf("AVERAGE TURN AROUND TIME=%f\nAVERAGE WAITING TIME=%f",(float)avg_tat/n,(float)avg_wt/n);
}


void main()
{
	int n;
	printf("ENTER THE NUMBER OF PROCCESSES:");
	scanf("%d",&n);
	int at[n],bt[n];
	for(int i=0;i<n;i++)
	{
		printf("\nENTER THE ARRIVAL TIME OF PROCCESS P%d:",i);
		scanf("%d",&at[i]);
		printf("ENTER THE BURST TIME OF PROCCESS P%d:",i);
		scanf("%d",&bt[i]);
	}
	fcfs(at,bt,n);
}
