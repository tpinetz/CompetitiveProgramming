#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

int n,m;
char grid[1010][1010];
int rows[1010];
int cols[1010];

int main() {
  cin >> n >> m;

  memset(cols,0,sizeof cols);
  memset(rows,0,sizeof rows);

  for(int i =0; i < n;i++) {
    scanf("%s",grid[i]);
  }

  int firstIdxX = -1;
  int firstIdxY = -1;

  for(int i = 0; i < n;i++) {
    for(int j = 0; j < m;j++) {
      if(grid[i][j] != '.') {
        firstIdxX = i;
        firstIdxY = j;
        rows[i]++;
        cols[j]++;
      }
    }
  }

  if(firstIdxX == -1) {
    cout << "YES" << endl;
    cout << "1 1";
    return 0;
  }

  bool first = false;

  int resIdxX = 0;
  int resIdxY = firstIdxY;

  for(int i = 0; i < n;i++) {
    if(rows[i] - (grid[i][firstIdxY] != '.') > 0) {
      if(!first) {
        first = true;
        resIdxX = i;
        resIdxY = firstIdxY;
      }
      else {
        resIdxX = -1;
        resIdxY = -1;
        break;
      }
    }
  }
  if(resIdxX == -1) {
    first = false;
    resIdxX = firstIdxX;
    resIdxY = 0;
    for(int i = 0; i < m; i++ ) {
      if(cols[i] - (grid[firstIdxX][i] != '.') > 0) {
        if(!first) {
          first = true;
          resIdxX = firstIdxX;
          resIdxY = i;
        }
        else {
          resIdxX = -1;
          resIdxY = -1;
          break;
        }
      }
    }
  }

  if(resIdxX != -1) {
    cout << "YES" << endl << resIdxX + 1 << " " << resIdxY + 1;
  } else {
    cout << "NO";
  }

  return 0;
}
