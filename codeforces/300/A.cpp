#include <stdio.h>
#include <string.h>

char input[10010];
int n;

int main() {
	scanf("%s",input);
	n = strlen(input);
	
	char* testString = "CODEFORCES";
	
	int j = 0;
	int n2 = strlen(testString);
	bool flag = false;
	bool cur = false;
	bool found = false;
	
	for(int i = 0; i < n && !found;i++) {
		if(j == n2) found = true;
		
		
		for(int k = i+1;k < n;k++) {
			int temp = j;
			for(int l = k; l < n;l++) {
				if(temp == n2) found = true;
				if(input[l] == testString[temp]) temp++;
				else break;
			}
			if(temp == n2) found = true;
		}
		
		if(input[i] == testString[j]) j++;
		else break;
	}
	
	
	if(found) printf("YES");
	else printf("NO");
	

	return 0;
}
