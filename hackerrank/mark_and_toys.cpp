#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long int 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	LL N, K;
	cin>>N;
	cin>>K;
	vector<LL> val;
	while(N) {
	  LL v;
	  cin>>v;
	  val.push_back(v);
	  --N;
	}
	sort(val.begin(), val.end());
	LL count = 0;
	LL sum = 0;
	while(true) {
	  sum += val[count];
	  if(sum > K) {
	    break;
	  }
	  ++count;
	}
	cout<<count;
    return 0;
}
