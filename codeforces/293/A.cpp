#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	
	char s[110];
	char t[110];
	scanf("%s",s);
	scanf("%s",t);
	bool flag = false;
	for( int i = strlen(s)-1;i>= 0;i--) {
		if(s[i] == 'z') s[i] = 'a';
		else {
			s[i] +=1;
			flag = true;
			break;
		}
	}
	
	
	if(!flag) {
		printf("No such string");	
	} else {
		flag = false;
		for( int i = 0;i < strlen(s);i++) {
			if(s[i] < t[i]) {
				flag = true;
				break;
			}
			else if(s[i] == t[i]) continue;
			else break;
			
		}
		if(!flag) printf("No such string");
		else printf("%s",s);
	
	}
	
	return 0;
}
