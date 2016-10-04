#include <stdio.h>
#include <queue>
#include <list>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
  int inDegree;
  list<long long> to;
  list<long long> from;
  long long x;
  long long y;
  bool visited;
  bool deleted;
  bool inStack;
};

Node graph[100100];
long long m;
long long mod = 1000000009;

priority_queue< long long, vector< long long> > vash;
priority_queue< long long, vector<long long>, greater<long long> > pet;

map<pair<long long,long long>,long long> myMap;

queue<long long> q;

void printGraph() {
  for(int i = 0; i < m;i++) {
    cout << i << " ";
    for(list<long long>::iterator it = graph[i].to.begin();
      it != graph[i].to.end();it++) cout << *it << " ";
    cout << endl;
  }
}

void addVertex(long long idx,long long index) {
    //cout << "idx: " << idx << " index: " << index << endl;
    graph[idx].to.push_back(index);
    graph[index].from.push_back(idx);
    graph[idx].inDegree++;

    vash.push(idx);
    pet.push(idx);

    q.push(idx);
}

int main() {

  cin >> m;

  for(long long i = 0; i < m;i++) {
    long long x,y;
    cin >> x >> y;
    graph[i].inDegree = 0;
    graph[i].visited = false;
    graph[i].deleted = false;
    graph[i].x = x;
    graph[i].y = y;
    myMap[make_pair(x,y)] = i;
    if(y == 0) q.push(i);
  }

  while(!q.empty()) {
    long long index = q.front();
    q.pop();

    if(graph[index].visited) continue;
    map<pair<long long, long long>, long long >::iterator it =
      myMap.find(make_pair(graph[index].x-1,graph[index].y+1));
    if(it != myMap.end()) {
      addVertex(it->second,index);
    }
    it = myMap.find(make_pair(graph[index].x,graph[index].y+1));
    if(it != myMap.end()) {
      addVertex(it->second,index);
    }
    it = myMap.find(make_pair(graph[index].x+1,graph[index].y+1));
    if(it != myMap.end()) {
      addVertex(it->second,index);
    }
    graph[index].visited = true;
  }


  //printGraph();

  bool turn = true;
  long long result = 0;
  while(true) {
    long long curElement = 0;
    if(turn) {
      if(vash.empty()) break;
      curElement = vash.top();
      vash.pop();
    } else {
      if(pet.empty()) break;
      curElement = pet.top();
      pet.pop();
    }

    //cout << curElement << endl;

    if(graph[curElement].deleted) continue;

    bool flag = true;
    for(list<long long>::iterator it = graph[curElement].from.begin();
    it != graph[curElement].from.end();it++) {
      if(!graph[*it].deleted) {
        if(graph[*it].inDegree == 1) flag = false;
      }
    }

    if(!flag) continue;


    turn = !turn;

    result = (result*m)%mod;
    result = (result + curElement) % mod;

    graph[curElement].deleted = true;
    graph[curElement].inDegree = 0;

    for(list<long long>::iterator it = graph[curElement].from.begin();
          it != graph[curElement].from.end();it++) {
          if(!graph[*it].deleted) {
              graph[*it].inDegree--;
          }
    }

    for(list<long long>::iterator it = graph[curElement].to.begin();
    it != graph[curElement].to.end();it++) {
      if(!graph[*it].deleted) {
        vash.push(*it);
        pet.push(*it);
      }
    }

  }

  cout << result;
  return 0;
}
