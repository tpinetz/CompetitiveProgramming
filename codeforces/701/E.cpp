#include <stdio.h>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int cnt[200200];

vector<int> graph[200200];

int dad[200200];
long long result = 0;
int n,k;

void DFS(int idx) {
    //cout << "Entering dfs: " << idx << endl;
    for(vector<int>::iterator it = graph[idx].begin(); it != graph[idx].end();it++) {
        if(*it != dad[idx]) {
            dad[*it] = idx;
            DFS(*it);
            cnt[idx] += cnt[*it];
        }
    }
    result += min(cnt[idx], 2*k - cnt[idx]);
    //cout << idx << "/" << min(cnt[idx], 2*k - cnt[idx]) << endl;
}

int main() {
    memset(dad,0,sizeof dad);
    memset(cnt,0, sizeof cnt);
    scanf("%d %d",&n, &k);
    for(int i = 0; i < 2*k;i++) {
        int x;
        scanf("%d",&x);
        cnt[x] = 1;
    }

    for(int i = 0; i < n-1;i++) {
        int x,y;

        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    DFS(1);

    cout << result;

    return 0;
}
