#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int n;

string seq;
int digits[1010];

int solve(string s, int idx) {
    int result;
    if(idx == s.size() - 1) {
        if(s[idx] == '9') {
            return 1989;
        } else {
            return 1990 + s[idx] - '0';
        }
    } else {
        int prev = solve(s, idx + 1);
      //  cout << "prev: " << prev << ": solve(" << s << ", " << idx + 1 << endl; 
        
        int ndigits = 0;
        int temp = prev;
        while(temp != 0) {
            digits[ndigits++] = temp  % 10;
            temp/=10;
        }
        
        int curDig = s.size() - idx - 1;
        
        if(digits[curDig] == s[idx] - '0') {
            result = prev + pow(10, curDig + 1);
        } else {
            int diff;
            if(digits[curDig] > s[idx] - '0') {
                diff = abs( 10 + (s[idx] - '0') - digits[curDig]);
            } else {
                diff = abs((s[idx] - '0') - digits[curDig]);                
            }
           // cout << diff;
            result = prev + diff * pow(10,curDig);
        }
    }
    
    return result; 
}

int main() {
    cin >>n;
    
    for(int i = 0; i < n;i++) {
        cin >> seq;
        int res = solve(seq, 4);
        cout << res << endl;
    }   
    
    
    return 0;
}