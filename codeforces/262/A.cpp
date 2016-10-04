#include <stdio.h>

int n,m;

int main() {
	scanf("%d %d",&n,&m);

	int result = 0;
	while(n > 0) {
		n--;
		result++;
		if(result %m == 0) n++;
	}
	printf("%d",result);
}