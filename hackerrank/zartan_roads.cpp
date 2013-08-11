#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define LL long long int
using namespace std;

vector < vector<int> > adj_list;
vector<int> colors;
bool flag;
void dfs_visit(int i, int j, int len) {
  colors[i] = 1; //GRAY;
  int idx = adj_list[i][0];
  if(idx < 0) return;
  if (idx == j && len) {
    flag = true;
    return;
  } 
  if (!colors[idx])
    dfs_visit(idx, j, ++len);
  colors[idx] = 2; // BLACK

}


int main() {
  int N, R;
  cin>>N;
  cin>>R;
  adj_list.resize(N+1);
  colors.resize(N+1);
  for(int i=0;i<N;i++) {
    adj_list[i].resize(1, -1);
    colors[i] = 0; //WHITE
  }
  while(R) {
    int a, b;
    cin>>a;
    cin>>b;
    adj_list[a][0] =  b;
    --R;
  }  
  for(int i=0;i<N;i++) {
    if (!colors[i]) {  //WHITE
      flag = false;
	  dfs_visit(i, i, 0);
	  if (flag) {
	    cout<<"YES";
	    return 0;
	  }
	} 
  }
  cout<<"NO";
}
