#include <stdio.h>

int A,B;

int main() {
  scanf("%d %d", &A, &B);


  int result = 0;
  while(A > 0 && B > 0 && !(A == 1 && B == 1) ) {
    if(B <= 2) {
      B++;
      A-=2;
    } else {
      A++;
      B-=2;
    }
    result++;
  }
  printf("%d",result);
  return 0;
}
