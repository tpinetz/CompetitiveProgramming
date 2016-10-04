#include <stdio.h>

int n = 100000;
int n1 = 99999;


int main() {
	printf("%d %d %d\n",n,n,1);
	for(int i = 1; i <= n;i++) {
		printf("%d\n",i);
	}
	for(int i = 0; i < n;i++) {
		if(i %2) printf("%d\n",n1);
		else printf("%d\n",n);
	}
	
}
