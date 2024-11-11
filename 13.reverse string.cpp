#include<stdio.h>
#include<string.h>
int main(){
	char str[100],temp,ori[100];
	printf("Enter a string: ");
	scanf("%s",str);
	strcpy(ori,str);
	int l=strlen(str);
	int s,e;
	s=0;
	e=l-1;
	while(s<e){
		temp=str[s];
		str[s]=str[e];
		str[e]=temp;
		s++;
		e--;
	}
	printf("Reversed String: %s\n",str);
	
	return 0;
}
