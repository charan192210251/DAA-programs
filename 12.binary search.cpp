#include<stdio.h>
int binarySearch(int arr[],int n,int target){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==target){
			return mid;
		}
		if(arr[mid]<target){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}
int main(){
	int i,n,target;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter target: ");
	scanf("%d",&target);
	int result=binarySearch(arr,n,target);
	if(result!=-1){
		printf("Element found at index %d",result);
	}
	else{
		printf("Element not found");
	}
	return 0;
}
