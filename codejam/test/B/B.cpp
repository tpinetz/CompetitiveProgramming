#include <stdio.h>
#include <string.h>

int T;

char pan[1010];

int main() {
	scanf("%d",&T);
	for(int t = 1; t <= T;t++) {
		scanf("%s",&pan);
		int n = strlen(pan);
		bool firstMinus = false;
		int result = 0;

		bool prevMinus = (pan[0] == '-');

		for(int i = 0; i < n;i++) {
			if(pan[i] == '-' && !prevMinus) {
				prevMinus = true;
			} else if(pan[i] == '+') {
				if(prevMinus) {
					result += (1 + firstMinus);
					firstMinus = true;
				}
				firstMinus = true;
				prevMinus = false;
			} 
		}

		if(prevMinus) {
			result += (1 + firstMinus);
		}

		printf("Case #%d: %d\n",t, result);
	}
}