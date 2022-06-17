#include<stdio.h>
int main()
{
    int i=0,n,b,a[4]={0,};
    scanf("%d",&n);
    for(;n>0;i++) {
        a[i]=n%10;
        n=n/10;
        if(n==0) {
            b=i;
        }
    }
    for(i=b;i>=0;i--) {
        if(i==2) {
            for(int j=0;j<a[i];j++) {
                printf("B");
            }
        } else if(i==1) {
            for(int j=0;j<a[i];j++) {
                printf("S");
            }
        } else {
            for(int j=0;j<a[i];j++) {
                printf("%d",j+1);
            }
        }
    }
    printf("\n");
    return 0;
}
