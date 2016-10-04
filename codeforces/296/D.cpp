#include <stdio.h>
#include <iostream>

using namespace std;


int n;
long long xtab[200200];
long long wtab[200200];

pair<long long, long long> weightTab[200200];

long long bsearch(long long x) {
	int beg = 0;
	int end = n;
	while( beg < end) {
		int i = (beg+end)/2
		if(weightTab[i].first <= x) {
			beg = i;
		} else
	}
}

int main() {
	scanf("%d",&n);
	
	for(int i = 0; i<  n;i++) {
		cin >> xtab[i] >> wtab[i];
	}

	return 0;
}
