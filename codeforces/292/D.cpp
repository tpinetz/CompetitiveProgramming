#include <stdio.h>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	list<pair<int,char> > to;
	char degree;
	bool deleted;
	char color;
};

char inputTab[2020][2020];
int n,m;

queue<int> q;

Node graph[4000010];

void addEdge(int x,int y,int x2,int y2,int color) {
	if(inputTab[x][y] == '.') {
		graph[x2*m+y2].to.push_back(make_pair(x*m+y,color));
		graph[x2*m+y2].degree++;
	}
}

int main() {
	scanf("%d %d",&n,&m);
	
	for(int i = 0; i< n;i++) {
		scanf("%s",inputTab[i]);
	}
	
	for(int i = 0; i < n*m;i++) {
		graph[i].degree = 0;
		graph[i].deleted = false;
	}
	
	for(int i = 0;i < n;i++) {
		for(int j = 0; j < m;j++) {
			if(inputTab[i][j] != '*' ) {
				if(j != 0) {
					addEdge(i,j-1,i,j,1);
				} 
				if(i != 0) {
					addEdge(i-1,j,i,j,3);
				}
				if(i != n-1) {
					addEdge(i+1,j,i,j,2);
				}
				if(j != m-1) {
					addEdge(i,j+1,i,j,0);
				}
				if( graph[i*m+j].degree == 1) q.push(i*m+j);
			} else {
				graph[i*m+j].deleted = true;
				graph[i*m+j].color = -1;
			}
		}
	}
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if(graph[cur].deleted) continue;
		if(graph[cur].degree == 0) break;
		
		
		graph[cur].deleted = true;
		pair<int, char> other = graph[cur].to.front();
		graph[cur].color = other.second;
		if(other.second == 0 || other.second == 2) graph[other.first].color = other.second+1;
		else graph[other.first].color = other.second-1;
		
		graph[other.first].deleted = true;
		
		while(!graph[other.first].to.empty()) {
			pair<int, char> nextElement = graph[other.first].to.front();
			graph[other.first].to.pop_front();
			graph[other.first].degree --;
			for(list<pair<int,char> >::iterator it = graph[nextElement.first].to.begin(); it != graph[nextElement.first].to.end();it++) {
				if(it->first == other.first) {
					it = graph[nextElement.first].to.erase(it);
					graph[nextElement.first].degree--;
				}
			}
			if(graph[nextElement.first].degree == 1) q.push(nextElement.first);
		}		
	}
	
	bool flag = true;
	for(int i = 0; i < n*m;i++) {
		if(!graph[i].deleted) flag = false;
	}
	
	if(flag) {
		for(int i = 0; i < n*m;i++) {
			if(graph[i].color == -1) {
				printf("*");
			} else if(graph[i].color == 0) {
				printf("<");
			} else if(graph[i].color == 1) {
				printf(">");
			} else if(graph[i].color == 2) {
				printf("^");
			} else {
				printf("v");
			}
			
			if( ((i+1) % m) == 0) printf("\n");
		}
	} else {
		printf("Not unique");
	}
	return 0;	
}
