#include <stdio.h>

int a,n;

int main() {
	scanf("%d %d",&n,&a);
	
	if( n == 1 ) {
		printf("1");
		return 0;	
	} else {
		int c = n - a ;
		int m = a-1; 
		if(c > m) {
			printf("%d",a+1);
		} else {
			printf("%d",a-1);
		}
	}
	
	return 0;
}
