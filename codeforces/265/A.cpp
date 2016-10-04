#include <iostream>
#include <string>

using namespace std;

int n;

string tab;

int main() {
	int val = 1;
	int ret = 0;
	cin >> n;
	cin >> tab;
	for(int i = 0; i<  n;i++) {
		int help = tab[i] - '0';
		if(val) {
			if(help == 1) {
				ret++;
			} else {
				val--;
				ret++;
			}
		} 
	}
	cout<<ret;
	return 0;
}