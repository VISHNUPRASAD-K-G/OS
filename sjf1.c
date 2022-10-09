#include<stdio.h>
#include<stdlib.h>

struct sjf
{
    int pid;
    int bt;
    int wt;
    int tat;
}p[10];

int main()
{
    int totwt=0,ttat=0;
    int n,i,j;
    struct sjf temp;
    printf("Enter The No; Of Process: ");
    scanf("%d",&n);

    printf("Enter The Process_id and Burst Time Of Each Process: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].pid);
        scanf("%d",&p[i].bt);
    }

    p[0].wt=0;
    p[0].tat=p[0].bt;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].bt>p[j].bt)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

            }
        }
    }

    for(i=0;i<n;i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;
        p[i].tat=p[i].wt+p[i].bt;
        totwt+=p[i].wt;
        ttat+=p[i].tat;
    }
    printf("Process\t\tBurst Time\t\tWaiting Time\t\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
    }

    printf("\nTotal Waiting Time= %d",totwt);
    printf("\nAverage Waiting Time= %d",totwt/n);
    printf("\nTotal TAT=%d",ttat);
    printf("\nAverage TAT=%d\n",ttat/n);
    return 0;
}

