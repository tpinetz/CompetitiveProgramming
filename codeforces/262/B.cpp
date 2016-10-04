#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


long long a,b,c;

long long maxInt = 1000000000;
long long minInt = 0;

long long results[100];
int n = 0;

long long repLong(long long z) {
	long long result = 0;
	while(z > 0 ) {
		result += (z%10);
		z/=10;
	}
	return result;
}

int main() {

	cin >> a >> b >> c;

	for(long long i = 0; i < 91;i++) {
		long long curNumb = b*pow(i,a)+c;
		if( curNumb > minInt && curNumb < maxInt) {
			if(repLong(curNumb) == i) results[n++] = (curNumb);
		}
	}
	cout << n << endl;

	for(int i = 0; i < n;i++) {
		cout << results[i] << " ";
	}
}