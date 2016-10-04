#include <stdio.h>
#include <string.h>
#include <memory.h>

int n;
char input[110];

int resultTab[100];

int main() {

  scanf("%d",&n);
  scanf("%s",input);

  memset(resultTab,0,sizeof resultTab);

  for(int i = 0; i < n;i++) {
    if(input[i] >= 'a' && input[i] <= 'z') {
      resultTab[input[i]-'a'] = 1;
    } else resultTab[input[i]-'A']=1;
  }

  bool flag = true;
  for(char c = 'a'; c <= 'z';c++) {
    if(!resultTab[c-'a']) flag = false;
  }

  if(flag) printf("YES");
  else printf("NO");

  return 0;
}
