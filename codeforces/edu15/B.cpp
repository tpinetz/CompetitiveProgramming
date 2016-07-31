#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;

long long tab[100100];
long long dup[100100];

int bsearch(long long x, int low, int h) {
    // todo bsearch
    int mid = (h + low)/2;
    if(h == low) return x == tab[low] ? low : -1;
    else if(tab[mid] >= x) return bsearch(x,low,mid);
    else return bsearch(x,mid + 1, h);

}

int main() {

    scanf("%d",&n);

    for(int i =0; i< n;i++) {
        scanf("%d",&tab[i]);
        dup[i] = 1;
    }

    sort(tab, tab + n);

    int dupli = 1;
    for(int i = 1; i < n;i++) {
        if(tab[i] == tab[i-dupli]) {
            dup[i-dupli]++;
            dupli++;
        } else {
            dupli = 1;
        }
    }


    long long curNum = 1;
    long long result = 0;
    for(long long i = 0; i <= 55;i++) {
        curNum *= 2;
        int k = 0;
        for(int j = 0; j < n; j+=dup[j]) {
            if(tab[j] >= curNum) break;

            int idx = bsearch(curNum - tab[j] ,j,n);
            if(idx != -1) {
                //cout << "nums: " << tab[j] << " " << tab[idx] << "/ curNum: " << curNum << endl;
                if(idx == j) {
                    result += dup[j] * (dup[j]-1) / 2;
                } else {
                    result += dup[j] * dup[idx];
                }
            }
        }

    }
    cout << result << endl;

}
