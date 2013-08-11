#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define LL long long int
using namespace std;

vector<LL> id;
vector<LL> si;

LL root(LL i) {
  while(i != id[i])
    i = id[i];
  return i;  
}

void Union (LL a, LL b) {
  LL i = root(a);
  LL j = root(b);
  if(i == j) return;
  if (si[i] < si[j]) {
    id[i] = j;
    si[j] += si[i];
    si[i] = 0;
  } else {
	id[j] = i;
	si[i] += si[j];
	si[j] = 0;
  }
}

bool same_country(LL a, LL b) {
  return root(a) == root(b);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    LL N, I;
    cin>>N;
    cin>>I;
	id.resize(N);
	for (LL i=0;i<N;++i) {
	  id[i] = i;
	}
	si.resize(N, 1);
	while (I) {
	  LL a, b;
	  cin>>a;
	  cin>>b;
	  Union(a, b);
	  --I;
	}
	LL res = 0;
	vector<LL> sum_arr(si.size()-1, 0);
	LL siz = sum_arr.size();
	sum_arr[siz-1] = si[si.size()-1];
	for (LL i=siz-2;i>=0;--i) {
	  sum_arr[i] = sum_arr[i+1]+si[i+1];
	  //cout<<sum_arr[i]<<endl;
	}
	/*for(LL i=0;i<si.size()-1;++i) {
	  if(!si[i]) continue;
	  for(LL j=i+1;j<si.size();++j) {
	    if (!si[j]) continue;  
	    res = res + (si[i] * si[j]);
	  }
	}*/
	for (LL i=0;i<si.size()-1;++i) {
	  res += si[i] * sum_arr[i];
	}
	cout<<res;
}

//2 7 4 3 9

