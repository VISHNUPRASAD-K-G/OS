#include<stdio.h>
#include<stdlib.h>

int main()
{
    int hp,max,nr,q[20],q1[20],q2[20],t,t1=0,t2=0,s,i,diff,seek=0,j;
    printf("Enter the no of request: ");
    scanf("%d",&nr);
    s=nr+1;
    int rq[s];
    printf("Enter the Initial Head position: ");
    scanf("%d",&hp);
    printf("Enter The max range of disk: ");
    scanf("%d",&max);

    printf("Enter the request sequence:\n");
    for(i=1;i<=nr;i++)
    {
        scanf("%d",&t);
        if(t>=hp)
        {
            q1[t1]=t;
            t1++;
        }
        else
        {
            q2[t2]=t;
            t2++;
        }
    }
    //sorting q1
    for(i=0;i<t1-1;i++)
    {
        for(j=i+1;j<t1;j++)
        {
            if(q1[i]>q1[j])
            {
                t=q1[i];
                q1[i]=q1[j];
                q1[j]=t;
            }
        }
    }

    //sorting q2
    for(i=0;i<t2-1;i++)
    {
        for(j=i+1;j<t2;j++)
        {
            if(q2[i]>q2[j])
            {
                t=q2[i];
                q2[i]=q2[j];
                q2[j]=t;
            }
        }
    }

    for(i=1,j=0;j<t1;i++,j++)
    rq[i]=q1[j];
    rq[i]=max;

    for(i=t1+2,j=0;j<t2;i++,j++)
    rq[i]=q2[j];
    rq[i]=0;
    rq[0]=hp;

    printf("\nEntered Queue:\n");
    for(i=0;i<=s;i++)
    {
        printf("%d",rq[i]);
    }
    printf("\n\n");
    for(j=0;j<nr+1;j++)
    {
       diff=abs(rq[j+1]-rq[j]);
       seek+=diff;
       if(j!=nr+1)
        printf("%d",rq[j]);
       else
        printf("%d\n",rq[j]);
    }
    seek-=rq[j-1];
    printf("Total Head Movement= %d",seek);
    return 0;
}
