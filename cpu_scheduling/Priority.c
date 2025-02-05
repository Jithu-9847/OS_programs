#include <stdio.h>

void priority(int at[], int bt[], int pri[], int n)
{
    int process[n], ct[n], tat[n], wt[n], temp_prio[n - 1];
    float avg_tat = 0, avg_wt = 0, time = 0;

    // Initialize process array
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1; // Process numbering starts from 1
    }
    for (int i = 1; i < n; i++)
        temp_prio[i] = 0;

    for (int i = n - 1; i > 0; i--) // for finding the process at the first arrival time
    {
        if (at[i] < at[i - 1])
        {
            int temp = at[i];
            at[i] = at[i - 1];
            at[i - 1] = temp;

            temp = bt[i];
            bt[i] = bt[i - 1];
            bt[i - 1] = temp;

            temp = process[i];
            process[i] = process[i - 1];
            process[i - 1] = temp;

            temp = pri[i];
            pri[i] = pri[i - 1];
            pri[i - 1] = temp;
        }
    }

    time += bt[0];
    ct[0] = time;

    for (int i = 1; i < n; i++) // For sorting the burst time
    {
        for (int j = 1; j < n - i; j++)
        {
            if (pri[j] > pri[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;
            }
        }
    }

    for (int j = 1; j < n; j++)
    {
        if (pri[j] == pri[j + 1]) // For finding the process when two burst times becomes equal
        {

            if (at[j] > at[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (at[j] <= time && temp_prio[j] == 0)
            {
                time += bt[j];
                ct[j] = time;
                tat[j] = ct[j] - at[j];
                wt[j] = tat[j] - bt[j];

                temp_prio[j] = 1;
                break;
            }
        }
    }

    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    // Print the result table
    printf("P\tAT\tBT\tPRIORITY\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", process[i], at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("AVERAGE TURN AROUND TIME=%f\nAVERAGE WAITING TIME=%f", (float)avg_tat / n, (float)avg_wt / n);
}

int main()
{
    int n;
    printf("ENTER THE NUMBER OF PROCCESSES:");
    scanf("%d", &n);
    int at[n], bt[n], pri[n];
    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE PRIORITY OF PROCCESS P%d:", i);
        scanf("%d", &pri[i]);
        printf("\nENTER THE ARRIVAL TIME OF PROCCESS P%d:", i);
        scanf("%d", &at[i]);
        printf("ENTER THE BURST TIME OF PROCCESS P%d:", i);
        scanf("%d", &bt[i]);
    }
    priority(at, bt, pri, n);
}
