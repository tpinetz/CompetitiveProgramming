#include <stdio.h>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int T;

int N,J;

int maxDiv = 50;
int prims[100100];
int result[500][11];
int digPrimes[100];

vector<int> primes;
int temp[100];

int divWithBase(int* digits, int base, int* primeDigits, int n) {
	int rest = 0;
	int tempN = 0;
	for(int i = 0; i < n;i++) {
		temp[tempN++] = digits[i];
	}

	bool finished = false;
	int offset = 0;
	while(tempN + offset <= N) {
		bool bigger = false;
		bool equalCheck = true;

		/*	if(base == 2) {
				printf("offset: %d / tempN: %d / n: %d\n",offset, tempN, n);
				for(int i = 0; i< tempN;i++) {
					printf("%d",temp[i]);
				}	
				printf(" ");
				for(int i = 0; i < n;i++) {
					printf("%d", primeDigits[i]);
				}
				printf("\n");
			}*/

		if(tempN > n) {
			bigger = true;
			equalCheck = false;
		} else if(tempN < n) {
			bigger = false;
			equalCheck = false;
		} else {
			for(int i = 0; i < tempN; i++) {
				if(temp[i] > primeDigits[i]) {
					bigger = true;
					equalCheck = false;
					break;
				} else if(temp[i] < primeDigits[i]) {
					equalCheck = false;
					break;
				}
			}
		}
		//printf("equal: %d / bigger: %d \n", equalCheck, bigger);
		if(equalCheck) {
			tempN = 1;
			temp[0] = 0;
			offset += tempN;
		} else if(bigger) {

			int diff = tempN - n;
			for(int i = diff; i < tempN;i++) {
				if(temp[i] < primeDigits[i - diff]) {
					temp[i] = base + temp[i] - primeDigits[i-diff];
					int k = i-1;
					while(temp[k] == 0) {
						temp[k] = base - 1;
						k--;
					}
					temp[k]--;
				} else {
					temp[i] -= primeDigits[i-diff];
				} 
			}


		} else {
			if(tempN + offset >= N) break;
			temp[tempN] = digits[tempN + offset];
			tempN++;
		}
		int zeroDigits = 0;
		while(temp[zeroDigits] == 0 && zeroDigits < tempN) {
			zeroDigits++;
		}
		for(int i = zeroDigits; i < tempN;i++) {
			temp[i - zeroDigits] = temp[i]; 
		}
		tempN -= zeroDigits;
		offset+= zeroDigits;
	}

	if(tempN == 0) return 1;
	return -1;
}

int resultfindDivInBase(int *digits, int base) {
	for(int i = 0; i < primes.size();i++) {
		int prime = primes[i];
/*		int n = 0;
		int tempP = prime;
		while(tempP > 0) {
			digPrimes[n++] = tempP % base;
			tempP /= base;
		}
		for(int i = 0; i < n/2;i++) {
			int help = digPrimes[i];
			digPrimes[i] = digPrimes[n-i-1];
			digPrimes[n-i-1] = help;
		}
		//printf("test: %d\n",prime);
		int res = divWithBase(digits, base, digPrimes, n );
		//printf("prime: %d / %d\n", prime, res);
		if(res != -1) return prime;*/
		long long num = 0;
		for(int i = 0; i< N;i++) {
			num *= base;
			num += digits[i];
		}
		if(num % prime == 0) return prime;

	}
	return -1;
}

int main() {
	scanf("%d",&T);
	srand (time(NULL));

	memset(prims, 1, sizeof prims);


	for(int i = 2; i < maxDiv;i++) {
		if(prims[i]) {
			primes.push_back(i);
			for(int j = 2; j <= maxDiv / i; j++ ) {
				prims[i*j] = 0;
			}
		}
	}

	int digits[110];
	int resultDigits[50][550];

	for(int t = 1; t <= T;t++) {
		scanf("%d %d",&N,&J);
		int resultFound = 0;

		digits[N-1] = 1;
		digits[0] = 1;

		while(resultFound < J) {
			for(int i = 1; i < N-1; i++) {
				digits[i] = rand() % 2;
			}
			bool alreadyFound = false;
			for(int j = 0; j < resultFound;j++) {
				bool found = true;
				for(int i =0; i < N; i++) {
					if(resultDigits[i][j] != digits[i]) found = false;
				}
				if(found) alreadyFound = true;
			}
			if(alreadyFound) continue;

		/*	for(int i = 0; i < N;i++) {
				printf("%d",digits[i]);
			}

			printf(" %d\n",resultFound);*/

			int base;

			for(base = 2; base < 11;base++) {
				result[resultFound][base] = resultfindDivInBase(digits, base);
				if(result[resultFound][base] == -1) break;
			}

			if(base == 11) {
				for(int i =0; i < N; i++) {
					resultDigits[i][resultFound] = digits[i];
				}

				resultFound++;
			}
		}

		printf("Case #%d:\n", t);
		for(int i = 0; i < J;i++) {
			for(int j = 0; j < N;j++) {
				printf("%d", resultDigits[j][i]);	
			}
			for(int j = 2; j < 11;j++) {
				printf(" %d",result[i][j]);
			}
			printf("\n");
		}
	}
}