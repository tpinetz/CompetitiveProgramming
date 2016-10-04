#include <iostream>
#include <memory.h>

using namespace std;

int n;
int tab[110];
bool taken[110];

int main() {
    memset(taken,0,sizeof taken);
    cin >> n;
    int sum = 0;
    for(int i = 0; i<  n; i ++) {
        cin >> tab[i];
        sum += tab[i];
    }

    int cc = sum / (n / 2);

    for(int i = 0; i< n;i++) {
        if(taken[i]) continue;
        taken[i] = true;
        for(int j = i+1;j < n;j++) {
            if(taken[j]) continue;

            if(tab[i] + tab[j] == cc) {
                taken[j] = true;
                cout << i + 1 << " " << j + 1 << endl;
                break;
            }
        }
    }
    return 0;

}
