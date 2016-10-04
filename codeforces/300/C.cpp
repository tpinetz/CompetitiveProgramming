#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m;

int dtab[100010];
int h[100010];

int main()  {
	int cur = 0;
	
	scanf("%d %d",&n,&m);
	
	scanf("%d %d",&dtab[0],&h[0]);
	
	int ans = h[0] + dtab[0] - 1;
	cur = dtab[0];
	
	bool pos = true;
	
	for(int i = 1; i < m;i++) {
		scanf("%d %d",&dtab[i],&h[i]);
		int difH = abs(h[i-1] - h[i]);
		int difD = dtab[i] - dtab[i-1];
		if(difD < difH) pos = false;
		
		if(h[i] > h[i-1]) ans = max(ans, (h[i] + (difD - difH) /2));
		else ans = max(ans, (h[i-1] + (difD - difH)/2));
		
	}
	
	ans = max(ans, h[m-1] + n - dtab[m-1]);
	
	
	if(pos) printf("%d",ans);
	else printf("IMPOSSIBLE");

	return 0;
}
