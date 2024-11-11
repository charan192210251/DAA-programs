#include<stdio.h>
#include<math.h>
int main(){
	int n,sum=0,rem,temp;
	printf("Enter a number: ");
	scanf("%d",&n);
	temp=n;
	while(n>0){
		rem=n%10;
		sum=sum+pow(rem,3);
		n/=10;
	}
	if(temp==sum)
	printf("%d is an Armstrong number",temp);
	else
	printf("%d is not an Armstrong number",temp);
	return 0;
}
