#include <stdio.h>
#include <string.h>

char A[110];
char B[110];

int main() {
    scanf("%s %s",&A,&B);
    
    int n = strlen(A);
    int m = strlen(B);
    
    bool eq = false;
    
    if(n == m) {
        eq = true;
        for(int i = 0; i < n;i++)  {
            if(A[i] != B[i]) eq = false;
        }
    }
    
    if(eq) {
        printf("%s",A);
    } else {
        printf("1");
    }
    
    
    return 0;
    
}