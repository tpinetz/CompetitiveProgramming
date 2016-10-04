#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

int dig[1010];

int main() {

	scanf("%d",&n);
	
	int help = n;
	int numDig = 0; 
	int maxDig = 0;
	while(help > 0 ) {
		dig[numDig++] = help%10;
		maxDig = max(maxDig,help%10);
		help /= 10;
	}
	
	
	printf("%d\n", maxDig);
	
	for(int i = 0; i < maxDig;i++) {
		int exp = 1;
		int ans = 0;
		for(int j = 0; j < numDig;j++) {
			if(dig[j]) {
				ans += exp;
				dig[j]--;
			}
			exp*=10;
		}
		
		printf("%d ",ans);
	}
	

}
