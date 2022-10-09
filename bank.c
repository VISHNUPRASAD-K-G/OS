#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
int avail[10],r,n,max[10][10],need[10][10],alloc[10][10],maxres[10],work[10],finish[10],safe[10];



int is_safe()
{
    int i=0,j,k=0,cnt=n;
    for(i=0;i<r;i++)
        work[i]=avail[i];
    for(i=0;i<r;i++)
        finish[i]=false;
    while(n>0)
    {
        for(i=0;i<n;i++)
        {
            i=find();
            if(i==-1)
            {
                printf("\nThe System Is In unsafe state.");
                return 0;
            }
            for(j=0;j<r;j++)
                work[j]+=alloc[i][j];
            safe[k++]=i;
            cnt--;
        }
    }
    if(finish[i-1]==false)
    {
        printf("\nThe System Is In Unsafe State.\n");
        return 0;
    }
    printf("\nThe system Is In Safe State");
    return 0;
}

int find()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(finish[i]==false)
        {
         for(j=0;j<r;j++)
                if(need[i][j]>work[j])
                    break;
                if(j==r)
                {
                    finish[i]=true;
                    return i;
                }
        }
    }
    return -1;
}






int main()
{
    int i,j,sum;
    printf("Enter The No: of Process:");
    scanf("%d",&n);
    printf("Enter The No: Of Resources: ");
    scanf("%d",&r);
    printf("Enter The Max Instances Of Resources:\n");
    for (i=0;i<r;i++)
    {
        scanf("%d",&maxres[i]);
        avail[i]=maxres[i];
    }
    printf("Enter The Allocation Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter The MAX Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("Need Matrix Is: ");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<r;j++)
        {
            printf("%d     ",need[i][j]);
        }
    }
    for(j=0;j<r;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=alloc[i][j];
        }
        avail[j]-=sum;
    }
    is_safe();
    return 0;
}


