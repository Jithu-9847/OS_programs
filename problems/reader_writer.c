#include<stdio.h>

int reading=0;
int writing=0;
int mutex=1;
int reader_count=0;


void read()
{
    --mutex;
    reading=1;
    reader_count++;
    printf("\nReader %d is reading...\n",reader_count);
    ++mutex;
}

void write()
{
    --mutex;
    writing=1;
    printf("\nWriter is writing...\n");
    ++mutex;
}

void main()
{
    int choice;

    do{
        printf("ENTER THE CHOICE:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(writing==0 && mutex==1)
            {
                read();
            }
            else{
                printf("\nCurrently a writer is writing...\n");
            }
            break;
        case 2:
            if(writing==0&&mutex==1&&reading==0)
            {
                write();
            }
            else if(reading==1)
            {
                printf("\nCurrently a reader is reading...\n");
            }
            else{
                printf("\nCurrently a writer id writing...\n");
            }
            break;
        case 3:
            if(writing==0)
            {
                printf("\nCurrently no writer is writing...\n");
            }
            else{
                printf("\nWriter is removed\n");
                writing=0;

            }
            break;
        case 4:
            if(reading==0)
            {
                printf("\nCurrently no reader is reading...\n");
            }
            else{
                printf("\nReader(%d) is removed...\n",reader_count );
                reader_count--;
                if(reader_count==0)
                {
                    reading=0;
                }
            }
            break;
        case 5:
            printf("\n Exiting code...\n");
        }

    }while(choice!=5);
}