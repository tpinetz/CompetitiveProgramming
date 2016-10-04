#include <iostream>
#include <memory.h>
using namespace std;

typedef long long ll;

ll n,m;

bool rows[100100];
bool cols[100100];

int main() {
    cin >> n >> m;

    ll row = n;
    ll col = n;

    for(ll i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if(!rows[x]) {
            rows[x] = true;
            row --;
        }
        if(!cols[y]) {
            cols[y] = true;
            col--;
        }

        cout << row * col << " ";
    }

    return 0;
}
