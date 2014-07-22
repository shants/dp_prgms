#include<iostream>
#include<vector>

using namespace std;

#define INF 999
int minCoin(vector<int> v,int S)
{
vector<int> SUM(S+1, INF);
vector<int> prev(S+1, -1);

SUM[0] = 0;
for(int i=0; i <= S; ++i) {
    for(int j=0; j < (int)v.size(); ++j) {
	if( (v[j] <= i) ) {
	    
	    SUM[i] = min(SUM[i], SUM[i-v[j]]+1);
	    if(SUM[i] == SUM[i-v[j]]+1)
		prev[i] = i-v[j];
	}  
    }

}
for(int i=0; i < (int) prev.size(); ++i)
    cout << "\n prev [ " << i << "] = " << prev[i];
   
return SUM[S];
}

int main()
{
vector<int>  v;
v.push_back(1);
v.push_back(3);
v.push_back(5);

cout << "\n ans is " << minCoin(v, 11);
return 0;
}
