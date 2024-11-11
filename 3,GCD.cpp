#include<stdio.h>
int main(){
	int a,b,rem;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	int n1=a;
	int n2=b;
	while(b!=0){
		rem=a%b;
		a=b;
		b=rem;	
	}
	printf("GCD of %d and %d is %d",n1,n2,a);
}
