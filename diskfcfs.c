#include<stdio.h>
#include<stdlib.h>

int main()
{
    int hp,nr,mov=0,i;
    printf("Enter the no of request: ");
    scanf("%d",&nr);
    int rq[nr];
    printf("Enter the request sequence:\n");
    for(i=0;i<nr;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter the Initial Head position: ");
    scanf("%d",&hp);
    mov=mov+abs(hp-rq[0]);
    printf("Movement Sequence Is:\n%d->%d",hp,rq[0]);
    for(i=1;i<nr;i++)
    {
        mov=mov+abs(rq[i]-rq[i-1]);
        printf("->%d",rq[i]);
    }
    printf("\nTotal Head Movement= %d\n",mov);
    return 0;
}
