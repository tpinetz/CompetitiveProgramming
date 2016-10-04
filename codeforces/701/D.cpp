#include <iostream>
#include <math.h>
using namespace std;

double n,l,v1,v2,k;

double eps = 0.0000001;


bool check(double time) {
    if(time>=l) return true;

    double timeInBus = k*time / (n-k);

    double y = ((l - time*v1) / ((v2/2. - v1/2.) + ((v2/2 - v1/2)*v1/v2))); // time for the bus per drive
    double x = time - y; // time on foot

    double disOfBus = y * (v1+v2) / 2;
    double lastPas = (timeInBus - y);

    cout << x << ":" << y << endl;

    cout << timeInBus << " ? " << lastPas * v2 + v1 * (time - lastPas) << endl;

    return y <= timeInBus && lastPas * v2 + v1 * (time - lastPas) >= l ;
}

double bsearch(double low, double high) {
    double mid = (low + high) / 2;
    cout << low << " / " << high << endl;
    if(check(mid)) {
        if(mid - low < eps) return mid;
        else return bsearch(low, mid);
    } else {
        return bsearch(mid,high);
    }
}

int main() {
    cin >> n >> l >> v1 >> v2 >> k;
    if(n==k) {
        cout << l / v2;
        return 0;
    }
    double result = bsearch(0, l);

    cout << result;
    return 0;
}
