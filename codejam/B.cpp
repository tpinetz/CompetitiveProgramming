#include <stdio.h>

int T;
int B;
long long M;

int btab[55][55];
long long dp[55];
bool visited[55];

bool correct = false;

bool solve(int idx, int pre) {
    if(idx == B-1) return 1;
    if(dp[idx] != -1 ) return dp[idx];
    
    long long sum = 0;
     
    for(int i = 0; i < B;i++) {
        if(btab[idx][i] && i != pre) {
            sum += solve(i, idx);
        }
    }
    
    return dp[idx] = sum;
}

bool construct(int x, int y) {
    if(x == B && y == B) {
            for(int i = 0; i < B;i++) {
                 dp[i] = -1;
                 visited[i] = false;
                
            }
        return solve(0,-1) == M;
    }
    
    if(x == B) {
        return construct(0, y + 1);
    }
    if(x == y ) return construct(x + 1, y); 
    
    btab[x][y] = 0;
    if(construct(x + 1, y)) return true;
    btab[x][y] = 1;
    return construct(x + 1,y);
    
}

int main() {
    
    scanf("%d",&T);
    for(int t = 1; t <= T;t++) {
        printf("Case #%d: ", t);
        correct = false;
        scanf("%d",&B);
        scanf("%lld",&M);
        
        if(construct(0,0)) {
            printf("POSSIBLE");
            for(int i = 0; i < B;i++) {
                printf("\n");
                for(int j = 0; j < B;j++) {
                    printf("%d ",btab[i][j]);
                }
            }
            printf("\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
        
    }
    
    return 0;
}