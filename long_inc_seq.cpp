#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
int main()
{
vector<int> v;
v.push_back(5);
v.push_back(3);
v.push_back(4);
v.push_back(8);
v.push_back(6);
v.push_back(7);

vector<int> len(v.size()+1,0);
len[0] = 0;
for(int i=0; i < v.size(); ++i)
{
    for(int j=0; j < i; ++j){
	if(v[j] <= v[i]) {
	    len[i] = max(len[j],len[i])+1;
	}
    }
}
cout << "ans is " <<*max_element(len.begin(), len.end()) << "\n" ;
return 0;
}
