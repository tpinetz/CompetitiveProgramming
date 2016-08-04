#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int T;
int tab[100];

int main() {
    scanf("%d",&T);
    for(int t = 1; t<= T;t++) {
        printf("Case #%d: ", t);
        scanf("%d",&n);
        for(int i = 0; i < n;i++) {
            scanf("%d",&tab[i]);
        }
        
        bool finished = false;
        
        while(true) {
            int maxVal = 0;
            int maxWithSameVal = 0;    
            for(int i = 0; i < n;i++) {
                if(tab[i] > maxVal) {
                    maxWithSameVal = 1;
                    maxVal = tab[i];
                } else  if(tab[i] == maxVal) {
                    maxWithSameVal++;
                }
            }
            
         
            if(maxVal == 0)  break;
            
            if(maxWithSameVal <= 2) {
                for(int i = 0; i < n;i++) {
                    if(tab[i] == maxVal) {
                        printf("%c", i + 'a');
                        tab[i]--;
                    }
                }
            } else {
                for(int i = 0; i < n;i++) {
                    if(tab[i] == maxVal) {
                        printf("%c", i + 'a');
                        tab[i]--;
                        break;
                    }
                }
            }
            printf(" ");
                
        }
        printf("\n");
        
    }
}