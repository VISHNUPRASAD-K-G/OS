#include<stdio.h>
#include<stdlib.h>


int main()
{
    int bt[20],wt[20],tat[20],i,j,n,temp1,temp2,temp3,p[20],comp[20],pid[20];
    float ttat=0.0,twt=0.0;
    printf("Enter The Number Of Process:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
        printf("Enter The Burst Time Of %d Process: ",pid[i]);
        scanf("%d",&bt[i]);
        printf("\tPriority: ");
        scanf("%d",&p[i]);

    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
            {
                temp1=p[i];
                p[i]=p[j];
                p[j]=temp1;
                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;
                temp3=pid[i];
                pid[i]=pid[j];
                pid[j]=temp3;
            }
        }
    }
    comp[0]=bt[0];
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        comp[i]=bt[i]+comp[i-1];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=comp[i];
        wt[i]=comp[i]-bt[i];
        ttat+=tat[i];
        twt+=wt[i];
    }
    printf("Process\t\tBurst Time\t\tWaiting Time\t\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]\t\t%d\t\t\t%d\t\t\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }

    printf("\nTotal Waiting Time= %f",twt);
    printf("\nAverage Waiting Time= %f",twt/n);
    printf("\nTotal TAT=%f",ttat);
    printf("\nAverage TAT=%f\n",ttat/n);
}
