#include <stdio.h>
#include <memory.h>

int n;
char S[200200];
char T[200200];

int Stab[40][40];
int Smiss[40];
int Tmiss[40];
int Ttab[40][40];

int main() {
	scanf("%d",&n);
	scanf("%s",S);
	scanf("%s",T);
	
	int ham = 0;
	
	int swapMax = 0;
	int idxI = -2;
	int idxJ = -2;
	
	memset(Smiss, -1,sizeof Smiss);
	memset(Tmiss, -1,sizeof Tmiss);
	memset(Stab,  -1,sizeof Stab);
	memset(Ttab,  -1,sizeof Ttab);
	
	for(int i = 0; i < n;i++) {
		if(S[i] != T[i]) {
			ham++;
			Smiss[S[i]-'a'] = i;
			Tmiss[T[i]-'a'] = i;
			Stab[S[i]-'a'][T[i]-'a'] = i;
			Ttab[T[i]-'a'][S[i]-'a'] = i;
		}		
	}
	
	//printf("ham: %d\n",ham);
	
	for(int i = 0; i <= 'z'-'a';i++) {
		if(Smiss[i] != -1 && Tmiss[i] != -1) {
			idxI = Smiss[i];
			idxJ = Tmiss[i];
			swapMax = 1;
			break;
		}
	}
	
	for(int i = 0; i <= 'z'-'a';i++) {
		for(int j = 0; j <= 'z'-'a';j++) {
			if(Stab[i][j] != -1 && Ttab[i][j] != -1) {
				idxI = Stab[i][j];
				idxJ = Ttab[i][j];
				swapMax = 2;
				break;
			}
		}
		if(swapMax == 2) break;
	}
	
	printf("%d\n%d %d",ham - swapMax,idxJ+1,idxI+1);
	return 0;
}
