#include <stdio.h>
#include<string.h>
int main() {
    char str[100], ori[100];
    int i;
    printf("Enter a string: ");
    scanf("%s",str);
	for(i=0;i<strlen(str);i++){
		ori[i]=str[i];
	}
	printf("%s",ori);
    return 0;
}

