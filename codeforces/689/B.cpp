#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int graph[200100];

int n;
int a[200100];

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n;i++) {
        graph[i] = 9999999;
    }
    for(int i =0; i < n;i++) {
        graph[i] = min(i,graph[i]);


        scanf("%d",&a[i]);
        graph[a[i]-1] = min(1 + graph[i], graph[a[i]-1]);
    }

    for(int i = 1; i < n;i++) {
        graph[i] = min(graph[i],graph[i-1] + 1);
    }

    for(int i = n-2; i> 0;i--) {
        graph[i] = min(graph[i], graph[i+1] + 1);
    }

    for(int i = 1; i < n;i++) {
        graph[i] = min(graph[i],graph[i-1] + 1);
    }


    for(int i =0 ; i < n;i++) {
        printf("%d ", graph[i]);
    }

    return 0;
}
