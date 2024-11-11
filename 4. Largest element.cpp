#include<stdio.h>
int main(){
	int n,i;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]>max)
		max=arr[i];
	}
	printf("Largest element: %d",max);
	return 0;
}
