#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m;

int myMax = 20020;

int dp[20020];

int main() {
  scanf("%d %d",&n,&m);

  long long result = 0;

  for(int i = 0; i< myMax;i++ ) {
    dp[i] = 999999;
  }

  dp[n] = 0;


  for(int i = 0; i< myMax/2;i++ ) {
    for(int j = 0; j < myMax;j++) {
      if(j*2 < myMax) {
        dp[j*2] = min(dp[j*2],dp[j]+1);
      }
      if(j > 0 ) {
        dp[j-1] = min(dp[j-1],dp[j]+1);
      }
    }
  }


  cout << dp[m];

  return 0;
}
