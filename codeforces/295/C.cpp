#include <stdio.h>
#include <memory.h>
#include <iostream>

using namespace std;

int n;
long long mod = 1000000007;
char input[100010];
long long numChars[5];
long long nChars = 0;

long long solve(int idx) {
  if( idx>= n) return 1;
  return ((nChars*solve(idx+1)) % mod);
}

int main() {
  memset(numChars,0,sizeof numChars);

  scanf("%d",&n);
  scanf("%s",input);

  for(int i =0; i< n;i++) {
    if(input[i] == 'A') numChars[0] +=1;
    else if(input[i] == 'C') numChars[1]+=1;
    else if(input[i] == 'G') numChars[2]+=1;
    else numChars[3]+=1;
  }

  long long curMax = max(numChars[0],max(numChars[1],max(numChars[2],numChars[3])));
  for(int i =0 ; i < 4;i++) nChars+= (numChars[i]==curMax);


  long long result = solve(0) % mod;

  cout << result;

  return 0;
}
