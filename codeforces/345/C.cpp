#include <map>
#include <stdio.h>
#include <algorithm>

using namespace std;

pair<long long, long long> xpairs[200020];
pair<long long, long long> ypairs[200020];
map< pair<long long,long long>, int> m;

int n;

int main() {
	long long duplicates = 0;
	scanf("%d",&n);
	for(int i = 0; i< n;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		xpairs[i] = make_pair(x,y);
		ypairs[i] = make_pair(y,x);
		if(m.count(xpairs[i])) {
			duplicates += m[xpairs[i]];
			m[xpairs[i]] ++;
		} else {
			m[xpairs[i]] = 1;
		}
	}
	
	sort(xpairs, xpairs + n);
	sort(ypairs, ypairs + n);
	
	long long xval = xpairs[0].first;
	int xvalItems = 1;
	long long yval = ypairs[0].first;
	int yvalItems = 1;
	long long result = 0;
	
	for(int i = 1; i < n;i++) {
		if(xval == xpairs[i].first) { 
			result+= xvalItems;
			xvalItems++;
		}
		else {
			xval = xpairs[i].first;
			xvalItems = 1;
		}
		if(yval == ypairs[i].first) {
			result+= yvalItems;
			yvalItems++;
			
		}
		else {
			yval = ypairs[i].first;
			yvalItems = 1;
		}
	}
	
	printf("%lld",result - duplicates);
	return 0;
	
}