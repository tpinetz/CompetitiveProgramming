#include <iostream>

using namespace std;

int n;
int tab[1010];


int main() {
	cin >> n;
	int beg = -1;
	for(int i = 0; i < n;i++) {
		cin >> tab[i];
		if(tab[i] == 1 && beg == -1) beg = i;
	}

	if(beg == -1) {
		cout << 0;
		return 0;
	}

	int act = 1;
	int result = 1;

	for(int i =beg+1; i < n;i++) {
		if(tab[i] == 1) {
			result += min(act,2);
			act = 0;
		}
		act++;
	}
	cout << result;
	return 0;

}