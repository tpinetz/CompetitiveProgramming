#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

char s[200010];
char t[200010];

int countBigS[30];
int countSmallS[30];

int countBigT[33];
int countSmallT[33];

int main() {
	scanf("%s",s);
	scanf("%s",t);
	
	memset(countBigS,0,sizeof countBigS);
	memset(countSmallS,0,sizeof countSmallS);
	
	memset(countBigT,0,sizeof countBigT);
	memset(countSmallT,0,sizeof countSmallT);
	
	int n = strlen(s);
	int m = strlen(t);
	
	for(int i = 0; i < n;i++) {
		if(s[i] >= 'a' && s[i] <= 'z') countSmallS[s[i]-'a']++;
		else countBigS[s[i]-'A']++;
	}
	
	for(int i = 0; i < m;i++) {
		if(t[i] >= 'a' && t[i] <= 'z') countSmallT[t[i]-'a']++;
		else countBigT[t[i]-'A']++;
	}
	
	int yeah = 0;
	int whoops = 0;
	
	for(int i = 0; i < 30;i++) {
	//	printf("%d %d %d %d %d\n",yeah, countBigS[i],countSmallS[i],countBigT[i],countSmallT[i]);
		if( countBigS[i] <= countBigT[i]) {
			yeah += countBigS[i];
			countBigT[i]-=countBigS[i];
			countBigS[i] = 0;
		} else {
			yeah += countBigT[i];
			countBigS[i] -= countBigT[i];
			countBigT[i] = 0;
		}
		if( countSmallS[i] <= countSmallT[i]) {
			yeah += countSmallS[i];
			countSmallT[i]-=countSmallS[i];
			countSmallS[i] = 0;
		} else {
			yeah += countSmallT[i];
			countSmallS[i] -= countSmallT[i];
			countSmallT[i] = 0;
		}
		
		countBigS[i] += countSmallS[i];
		countBigT[i] += countSmallT[i];
		whoops += min(countBigS[i],countBigT[i]);
	}
	
	printf("%d %d",yeah,whoops);
	return 0;	
	
}
