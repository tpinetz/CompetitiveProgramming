#include <stdio.h>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


multiset<int> xheap;
multiset<int> yheap;

set<int> xSet;
set<int> ySet;

int w,h,n;

int main() {
	scanf("%d %d %d",&w,&h,&n);
	
	xSet.insert(0);
	xSet.insert(w);
	
	xheap.insert(w);
	
	ySet.insert(0),
	ySet.insert(h);
	
	yheap.insert(h);
	
	for(int i = 0; i < n;i++) {
		char c[10];
		int mm;
		set<int>::iterator it;
		scanf("%s %d",c,&mm);
		if(c[0] == 'H') {
			it = (ySet.lower_bound(mm));
			
			int up = *it;
			it--;
			int lo = *it;
			
			yheap.erase(yheap.find(up-lo));
			yheap.insert(up-mm);
			yheap.insert(mm-lo);
			ySet.insert(mm);
			
			long long tempy = (*yheap.rbegin());
			long long tempx = (*xheap.rbegin());
			cout << (tempx * tempy) << endl;
			
		} else {
			it = (xSet.lower_bound(mm));
			int up = *it;
			it--;
			int lo = *it;
			
			xheap.erase(xheap.find(up-lo));
			xheap.insert(up-mm);
			xheap.insert(mm-lo);
			xSet.insert(mm);
			
			long long tempy = (*yheap.rbegin());
			long long tempx = (*xheap.rbegin());
			cout << (tempx * tempy) << endl;
		
		
		}
	}
	
	return 0;
}
