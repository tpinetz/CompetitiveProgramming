#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;

char seq[100100];
int dp[1010];

int main() {
    cin >> n;
    scanf("%s",seq);
    memset(dp, 0 , sizeof dp);
    int diff = 0;
    for(int i = 0; i < n;i++) {
        if(!dp[seq[i]]) {
            dp[seq[i]] = 1;
            diff ++;
        }
    }

    memset(dp, 0 , sizeof dp);

    int cur = 0;
    int j = 0;
    int result = n;
    for(int i = 0; i < n;i++) {
        while(j < n && cur < diff) {
            if(!dp[seq[j]]) {
                cur++;
            }
            dp[seq[j++]]++;
        }
        if(j == n && cur < diff) break;
        //cout << j << "/" << i << endl;
        result = min(result, j - i);
        dp[seq[i]] --;
        if(!dp[seq[i]]) cur--;
    }

    cout << result;
    return 0;
}
