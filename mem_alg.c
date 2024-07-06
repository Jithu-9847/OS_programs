#include<stdio.h>
 
//---------------FIRST FIT---------------------------
 
void f_f(int n,int m,int p[],int b[])
{
 	int a[n];
	for(int i=0;i<n;i++)
	{
	a[i]=-1;
		for(int j=0;j<m;j++)
		{
			if(p[i]<=b[j])
			{
				 a[i]=j;
				 b[j]=0;
				 break;
			}
			
		}
		 
	}
	
	
	printf("PROCESS\tP_SIZE\tBLOCK\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t",i,p[i]);
		if(a[i]==-1)
		{
			printf("NOT ALLOCATED\n");
		}
		else{
			printf("%d\n",a[i]);
		}
	}
}
//---------------------BEST FIT---------------------

void b_f(int n,int m,int p[],int b[])
{
 	int a[n],worst=-1,k;
	for(int i=0;i<n;i++)a[i]=-1;
	for(int i=0;i<n;i++)
	{
	
	worst=-1;
		
		for(int j=0;j<m;j++)
		{
			if(b[j]>=p[i] && (worst==-1 || b[j]-p[i]<b[worst]-p[i]) )
			{
				  worst=j;
				   
			}
			
		}
		if(worst!=-1)
		{
			a[i]=worst;
			b[worst]=0;
		}
		
		 
	}

	
	printf("PROCESS\tP_SIZE\tBLOCK\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t",i,p[i]);
		if(a[i]==-1)
		{
			printf("NOT ALLOCATED\n");
		}
		else{
			printf("%d\n",a[i]);
		}
	}
}

//-------------------------WORST FIT------------------------

void w_f(int n,int m,int p[],int b[])
{
 	int a[n],worst=-1,k;
	for(int i=0;i<n;i++)a[i]=-1;
	for(int i=0;i<n;i++)
	{
	
	worst=-1;
		
		for(int j=0;j<m;j++)
		{
			if(b[j]>=p[i] && (worst==-1 || b[j]-p[i]>b[worst]-p[i]) )
			{
				  worst=j;
				   
			}
			
		}
		if(worst!=-1)
		{
			a[i]=worst;
			b[worst]=0;
		}
		
		 
	}

	
	printf("PROCESS\tP_SIZE\tBLOCK\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t",i,p[i]);
		if(a[i]==-1)
		{
			printf("NOT ALLOCATED\n");
		}
		else{
			printf("%d\n",a[i]);
		}
	}
}


void main()
{
	int n,m;
	printf("ENTER THE NUMBER OF BLOCKS:");
	scanf("%d",&m);
	printf("ENTER THE NUMBER OF PROCESSES:");
	scanf("%d",&n);
	int b[m],p[n];
	printf("ENTER THE BLOCK SIZES:");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	
	printf("ENTER THE SIZE OF PROCESSES:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	
	f_f(n,m,p,b); //give appropriate function for each allocation method
	
	
}
