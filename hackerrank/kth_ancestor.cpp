#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define LL long long int
using namespace std;
#define MAX 100000
int main() {
  int T;
  cin>>T;
  while (T) {
	  LL P, Q, X, Y, K;
	  cin>>P;
	  vector<LL> par(MAX, -1);
	  while(P) {
	    cin>>X;
	    cin>>Y;
	    par[X] = Y;
	    --P;
	  }
	  cin>>Q;
	  while(Q) {
	    int cmd;
	    cin>>cmd;
	    //cout<<"cmd = "<<cmd<<endl;
	    switch(cmd) {
				
			  case 0:
			    //cout<<"In 0"<<endl;
			    cin>>Y;
			    cin>>X;
			    par[X] = Y;
			    
			    break;
			  case 1:
			    //cout<<"In 1"<<endl;
			    cin>>X;
			    par[X] = -1;
			    
			    break;
			  case 2:
			    //cout<<"In 0"<<endl;
			    cin>>X;
			    cin>>K;
			    while(K && par[X] && par[X] != -1) {
				    X = par[X];
				    --K;
				    //cout<<"K = "<<K<<endl;
				  }
				  if (!K) {
				    cout<<X<<endl;
				  } else {
				    cout<<0<<endl;      
				  }
				  break;
		   }
	    --Q;
	  }
	  --T;
  }
}
