#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a;

int tab[1010];

int main() {
	cin >> n >> a;
	int dig = 0;
	for(int i = 0; i < n;i++) {
		int cur = a % 10;
			if(cur == 4) {
				tab[dig++] = 3;
				tab[dig++] = 2;
				tab[dig++] = 2;
			} else if(cur == 6) {
				tab[dig++] = 5;
				tab[dig++] = 3;
			} else if(cur == 8) {
				tab[dig++] = 7;
				tab[dig++] = 2;
				tab[dig++] = 2;
				tab[dig++] = 2;
			} else if(cur == 9) {
				tab[dig++] = 7;
				tab[dig++] = 2;
				tab[dig++] = 3;
				tab[dig++] = 3;
			} else if(cur > 1) {
				tab[dig++] = cur;
			}
		
		a /= 10;
	}
	
	sort(tab,tab+dig,std::greater<int>());
	
	for(int i = 0; i< dig;i++) {
		printf("%d",tab[i]);
	}
	return 0;
	
}
