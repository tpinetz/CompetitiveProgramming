#include <stdio.h>

int n;
char seq[100100];
int times[30];

int main() {
    scanf("%d",&n);
    scanf("%s",seq);
    int res=0;
    for(int i = 0; i <=26;i++) {
        times[i] = 0;
    }
    if(n > 26) {
        res = -1;
    } else {
        for(int i = 0; i < n;i++) {
            times[seq[i]-'a']++;
        }
        for(int i = 0; i <= 26; i ++) {
            if(times[i] > 0) res += times[i] - 1; 
        }
    }
    
    printf("%d", res);
    
    return 0;
    
}