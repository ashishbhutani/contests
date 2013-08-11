#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define LL long long int
using namespace std;

void print_set(set<LL>& se) {
  cout<<"set:";
  for (set<LL>::iterator itr = se.begin(); itr != se.end(); ++itr) {
    cout <<*itr<<",";
  }
  cout<<endl;
}

void print_vec(vector< set<LL> >& vec) {
  cout<<"vector:"<<endl;
  for(vector< set<LL> >::iterator it = vec.begin(); it != vec.end(); ++it) {
    print_set(*it);
  }
  cout<<endl;
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    LL N, I;
    cin>>N;
    cin>>I;
	vector< set<LL> > vec;
	for (LL i=0;i<N;++i) {
	  set<LL> tmp;
	  tmp.insert(i);
	  vec.push_back(tmp);
	}
	//print_vec(vec);
	while (I) {
	  LL A, B;
	  cin>>A;
	  cin>>B;
	  for(LL i=0;i<vec.size();++i) {
	    if (vec[i].find(A) != vec[i].end()) {  // say 0 from (0,1) found
		  for (LL j=0;j<vec.size();++j) {  //search for 1 now
		    if (j == i) continue;
		    if (vec[j].find(B) != vec[j].end()) {   //1 found; which is guranteed also
		      LL idx = 0;
		      if (vec[i].size() > vec[j].size()) {
			    idx = j;
			    for (set<LL>::iterator it = vec[j].begin(); it != vec[j].end(); ++it) {
			      vec[i].insert(*it);  // insert all elem from 1's set to 0's set
			    }
			  } else {
			    idx = i;
			    for (set<LL>::iterator it = vec[i].begin(); it != vec[i].end(); ++it) {
			      vec[j].insert(*it);  // insert all elem from 1's set to 0's set
			    }
			  }
			  vec[idx].erase(vec[idx].begin(), vec[idx].end());  //remove 1's set completely
			}
		  }
		}
	  }
	  --I;
	}
	LL res = 0;
	for(LL i=0;i<vec.size()-1;++i) {
	  if(!vec[i].size()) continue;
	  for(LL j=i+1;j<vec.size();++j) {
	    if (!vec[j].size()) continue;  
	    res = res + (vec[i].size() * vec[j].size());
	  }
	}
	cout<<res;
}
