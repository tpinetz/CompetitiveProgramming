#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

string seq;
int result;

int plusQ = 0;
int minusQ = 0;

int main() {
    getline(std::cin, seq);
    int n = (seq.size());
    int i = 0;
    
    bool plus = true;
    
    while(seq[i] != '=') {
        if(seq[i] == '?') {
        plusQ += plus;
        minusQ += 1 - plus;
        } else {
           plus = seq[i] == '+'; 
        }
        i+= 2;
    }
    i+=2;
    while(i < n) {
        result = result * 10 + seq[i] - '0';
        i++;
    }
    
    if((plusQ*result > (minusQ + result) && minusQ*result >= plusQ-result) || (minusQ == 0 && plusQ == 1)) {
        cout << "Possible" << endl;
        
        int res = result + minusQ;
        
        int j =0 ;
        plus = true;
        while(seq[j] != '=') {
            if(seq[j] == '?') {
                if(plus) {
                    int num = min((res+plusQ-1)/plusQ, result);
                    cout << num << " ";
                    res -= num;
                    plusQ--;
                }  else {
                    cout << "1 ";
                }
            } else {
                if(seq[j] == '+') {
                    plus = true;
                    cout << "+ ";
                } else {
                    plus = false;
                    cout << "- ";
                }  
            }
            j+= 2;
        }
        cout << "= " << result;
        
    } else {
        cout << "Impossible";
    }
    
    return 0;
    
}