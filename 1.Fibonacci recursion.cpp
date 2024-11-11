#include<stdio.h>
int fibonacciSeries(int n){
	if(n<=1)
	return n;
	return fibonacciSeries(n-1)+fibonacciSeries(n-2);
}
int main(){
	int n,i;
	printf("Enter number of series: ");
	scanf("%d",&n);
	printf("Fibonacci series:\n");
	for(i=0;i<n;i++){
		printf("%d ",fibonacciSeries(i));
	}
	return 0;
}
