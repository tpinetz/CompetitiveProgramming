#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long cities[100100];
long long towers[100100];

int n,m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n;i++) {
        cin >> cities[i];
    }

    for(int i = 0; i < m;i++) {
        cin >> towers[i];
    }

    long long r= 0;
    int k = 0;
    for(int i = 0; i < n;i++) {
        long long curR = abs(cities[i] - towers[k]);
        while(k < m-1 && abs(towers[k+1] - cities[i]) <= curR) {
            curR = abs(towers[++k] - cities[i]);
        }
        //cout << curR << endl;
        r = max(r,curR);
    }

    cout << r;
}
