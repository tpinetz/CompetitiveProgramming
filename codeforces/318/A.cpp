#include <stdio.h>
#include <memory.h>

int n,m;
int input[110];
int res[110];

int main() {
	scanf("%d %d",&n,&m);
	
	memset(res, 0, sizeof(res));
	
	for(int i = 0; i < m ; i ++) {
		int idx = 0;
		for(int i = 0; i < n;i++) {
			scanf("%d",&input[i]);
			if(input[i] > input[idx]) idx = i;
		}
		res[idx]+=1;
	}
	
	int result = 0;
	for(int i = 0; i < n;i++) {
		if(res[i] > res[result]) result = i;
	}
	
	printf("%d",result+1);
	return 0;
}
