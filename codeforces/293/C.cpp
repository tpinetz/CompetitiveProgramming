#include <stdio.h>
#include <iostream>

using namespace std;

int n,m,k;
int input[100100];
int apps[100100];
int idxOfApp[100100];

int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i =1; i <= n;i++) {
		scanf("%d",&input[i]);
		idxOfApp[input[i]] = i;
	}
	
	long long result = 0;
	int idx = 0;
	int temp = 0;
	
	for(int i = 0; i < m;i++) {
		scanf("%d",&apps[i]);
		idx = idxOfApp[apps[i]];
		//printf("%d\n",idxOfApp[apps[i]]/k+1);
		result += (idx-1)/k+1;
		if(idx != 1) {
			temp = input[idx-1];
			input[idx-1] = input[idx];
			input[idx] = temp;
			idxOfApp[temp] = idx;
			idxOfApp[apps[i]] = idx-1;			
		}
	}
	cout << result;
	return 0;
}
