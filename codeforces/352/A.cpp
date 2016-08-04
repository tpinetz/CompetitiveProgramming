#include <stdio.h>

char prefix[1010];
int idx;

int main() {
    scanf("%d",&idx);
    
    int cur = 0;
    int curIdx = 0;
    char test[100];
    while(curIdx <= idx) {
        cur++;
        int temp = cur;
        int tempN = 0;
        while(temp != 0) {
            test[tempN++] = temp%10;
            temp/=10;
        }
        
        for(int i = tempN-1; i>= 0; i--) {
            prefix[curIdx++] = test[i];
        } 
    }
    
    printf("%d",prefix[idx-1]);
    
    return 0;
    
}