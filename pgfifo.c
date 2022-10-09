#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j=0,k,nf,np,avail,count=0;
    printf("Enter The No Of Pages:");
    scanf("%d",&np);
    int pg[np];
    printf("Enter The Pages:\n");
    for(i=0;i<np;i++)
    {
        scanf("%d",&pg[i]);
    }
    printf("Enter The No Of Frames: ");
    scanf("%d",&nf);
    int fr[nf];
    printf("REF String");
    for(i=0;i<nf;i++)
    {
        fr[i]=-1;
        printf("\tfr%d",i+1);
    }
    printf("\n");
    for(i=0;i<np;i++)
    {
        printf("%d\t\t",pg[i]);
        avail=0;
        for(k=0;k<nf;k++)
            if(fr[k]==pg[i])
                avail=1;
            if(avail==0)
            {
                fr[j]=pg[i];
                j=(j+1)%nf;
                count++;
                for(k=0;k<nf;k++)
                    printf("%d\t",fr[k]);
            }
            printf("\n");
    }
    printf("Number Of Page Fault: %d",count);


    return 0;
}
