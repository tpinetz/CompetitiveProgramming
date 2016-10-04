#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int n,m;
int b,g;
int btab[110];
int gtab[110];

bool flag = true;

int tryout(vector<int>& from,vector<int>& to,int index,int incrementor, int* tab) {
	while(index < from.size()) {
		int temp = from[index];
		for(int i = 0; i <= n*m; i+=incrementor) {
			if(i == 0) {
				if(!tab[temp]) {
					tab[temp] = 1;
					to.push_back(temp);
					flag = true;
				}
			} else {
				if(!tab[temp%i]) {
					tab[temp%i] = 1;
					to.push_back(temp);
					flag = true;
				}
			}
		}
		index++;
	}
	return index;
}


int main() {

	vector<int> boys;
	vector<int> girls;
	
	memset(btab,0,sizeof btab);
	memset(gtab,0,sizeof gtab);
	
	scanf("%d %d",&n,&m);
	scanf("%d",&b);
	for(int i = 0; i < b;i++) {
		int x;
		scanf("%d",&x);
		btab[x] = 1;
		boys.push_back(x);
	}
	
	scanf("%d",&g);
	for(int i = 0; i < g;i++) {
		int x;
		scanf("%d",&x);
		gtab[x] = 1;
		girls.push_back(x);
	}
	
	int idxb = 0;
	int idxg = 0;
	
	for(int i = 0; i <= n*m;i++) {
		if(btab[i%n] || gtab[i%m]) {
			btab[i%n] = 1;
			gtab[i%m] = 1;
		}
	}
	
	for(int i = 0; i <= n*m;i++) {
		if(btab[i%n] || gtab[i%m]) {
			btab[i%n] = 1;
			gtab[i%m] = 1;
		}
	}
	
	for(int i = 0; i< n;i++) {
		if(!btab[i]) flag = false;
	}
	
	for(int i = 0; i< m;i++) {
		if(!gtab[i]) flag = false;
	}
	
	if(flag) printf("Yes");
	else printf("No");

	return 0;
}
