#include <stdio.h>
#include <vector>

using namespace std;

struct node {
  int leader;
  int size;
  vector<int> to;
};

int n;
node graph[200200];
int result[200200];
int tab[200200];

vector<int> groupLeader;

void dfsMark(int idx, int leader) {
  graph[idx].leader = leader;
  for(vector<int>::iterator it = graph[idx].to.begin(); it != graph[idx].to.end(); it++) {
    if(graph[*it].leader != leader) {
      dfsMark(*it, leader);
    }
  }
}

int find(int idx) {
  if(graph[idx].leader != graph[graph[idx].leader].leader)  graph[idx].leader = find(graph[idx].leader);
  return graph[idx].leader;
}

bool unionG(int x, int y) {
  int xx = find(x);
  int yy = find(y);
  if(xx == yy) return false;

  if(graph[xx].size > graph[yy].size) {
    int t = xx;
    xx = yy;
    yy = t;
  }

  if(graph[xx].size == graph[yy].size) graph[yy].size++;

  graph[xx].leader = yy;
  return true;
}

int main() {
  scanf("%d",&n);
  for(int i = 1; i <= n;i++) {
    graph[i].leader = i;
    graph[i].size = 1;
  }

  int groups = n;
  bool rooted = false;

  for(int i = 1; i <= n;i++) {
    int x;
    scanf("%d",&x);
    tab[i] = x;
    if(x == i) rooted = true;
    graph[i].to.push_back(x);
    graph[x].to.push_back(i);
    if(unionG(i,x)) {
      groups--;
      result[i] = -1;
    } else {
      result[i] = x;
    }
  }

  for(int i = 1; i <= n;i++) {
    if(graph[i].leader == i) {
      groupLeader.push_back(i);
    }
  }

  int cnt = groups - rooted;
  int j = 2;
  int group = graph[1].leader;
  bool rootFound = false;
  for(int i = 1; i <= n;i++) {
    if(result[i] != -1) {
      if(result[i] == i && !rootFound) {
        rootFound = true;
      } else if (!rootFound && !rooted) {
        rootFound = true;
        result[i] = i;
      } else {
          vector<int>::iterator it;
          for( it = groupLeader.begin(); it != groupLeader.end();it++) {
            if(unionG(*it,i)) {
              result[i] = *it;

              break;
            }
          }
      }
      //printf("test: %d / %d\n", i, result[i]);
    } else {
      result[i] = tab[i];
    }
  }

  printf("%d\n", groups - rooted);

  for(int i = 1; i <= n;i++) {
    printf("%d ", result[i]);
  }

  return 0;
}
