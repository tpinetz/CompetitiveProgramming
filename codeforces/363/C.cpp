#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;


int n;
int tab[110];

int dp[110][4];

int solve(int idx, int act) {
  if(idx == n) return 0;
  if(dp[idx][act] != -1) return dp[idx][act];

  int result = 999;

  if(tab[idx] == 0) {
    result = 1 + solve(idx+1, 0);
  }
  if(tab[idx] == 1 || tab[idx] == 3) {
    if(act != 1) {
      result = solve(idx+1, 1);
    } else {
      result = 1 + solve(idx+1, 0 );
    }
  }
  if(tab[idx] == 2 || tab[idx] == 3) {
    if(act != 2) {
      result = min(result, solve(idx+1, 2));
    } else {
      result = min(result, 1 + solve(idx+1,0));
    }
  }

  return (dp[idx][act] = result);

}

int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n;i++) {
    cin >> tab[i];
  }

  int result = solve(0,0);

  cout << result;

}
