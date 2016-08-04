#include <stdio.h>

int T;
int N;

long long digits[100010];
int hasDigit[10];
int result[1000010];

bool checkDigits() {
    for(int i = 0; i < 10; i++) {
      if(!hasDigit[i]) return false;
    }
    return true;
}

int main() {
  scanf("%d",&T);

  for(int t = 1; t <= T; t++) {
    for(int i = 0; i < 10;i++) hasDigit[i] = 0;
    scanf("%d",&N);
    if(N == 0) {
      printf("Case #%d: INSOMNIA\n", t);
      continue;
    }

    int n = 0;
    while(N > 0) {
      digits[n++] = N%10;
      hasDigit[N%10] = 1;
      N /= 10;
    }
    bool finished = false;
    int curMultiplyer = 2;
    long long next = 0;
    int resultN;
    while(!checkDigits()) {
      int i = 0;
        for(i = 0; i < n; i++) {
            long long digit = digits[i]*curMultiplyer;
            digit += next % 10;
            next /= 10;
            next += digit / 10;
            digit = digit % 10;

            hasDigit[digit] = 1;
            result[i] = digit;
        }
        while(next > 0) {
          result[i++] = next % 10;
          hasDigit[next % 10] = 1;
          next /= 10;
        }
        curMultiplyer++;
        resultN = i;
    }
    printf("Case #%d: ", t);
    for(int i = resultN-1; i >= 0;i--) {
      printf("%d",result[i]);
    }
    printf("\n");

  }

}
