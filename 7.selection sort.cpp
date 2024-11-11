#include<stdio.h>
void selectionSort(int arr[],int n){
	int i,j,minIndex,temp;
	for(i=0;i<n;i++){
		minIndex=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[minIndex]){
				minIndex=j;
			}
		}
		if(minIndex!=i){
			temp=arr[i];
			arr[i]=arr[minIndex];
			arr[minIndex]=temp;
		}
	}
}
void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int i,n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Before Sorted:\n");
	printArray(arr,n);
	selectionSort(arr,n);
	printf("After Sorted:\n");
	printArray(arr,n);
	return 0;
}
