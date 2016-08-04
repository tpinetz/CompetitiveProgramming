#include <stdio.h>
#include <memory.h>

int a[1010];
int dp[1010];
int n;

int main() {
  scanf("%d",&n);

  for(int i = 0; i<  n; i ++) {
    scanf("%d",&a[i]);
  }

  memset(dp, 0 , sizeof dp);

  for(int i = 0; i< n;i++) {
      dp[a[i]]++;
  }
  int result = 0;
  for(int i =0 ; i < n; i++) {
    int temp = 0;
    for(int j =0; j< 1001;j++) {
      if(dp[j])  {
        dp[j]--;
        temp++;
      }
    }
	if (temp) result += temp - 1;
  }

  printf("%d",result);

  return 0;
}
