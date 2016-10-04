#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;


int main() {

	long long a;
	long long b;
	
	cin >> a >> b;	

	long long times = 0;
	while( b > 0) {
		long long cur = a/b;
		times += cur;
		a -= cur*b;
		if(a < b )  {
			long long help = a;
			a = b;
			b = help;
		}
	}
	
	cout << times;

	return 0;
}
