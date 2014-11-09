#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
// 30 35 15 5 10 20 25
vector<float> sz;
sz.push_back(1);
sz.push_back(2);
sz.push_back(3);
sz.push_back(4);
sz.push_back(3);

int n = sz.size();
float tbl[10][10];
//initialize array
for(int i=0; i <= n;++i)
 {
    for(int j=0; j <= n;++j)
	tbl[i][j] = 99999;
 }   

// begin dp, 1st step init
// mark tbl[i][i] = 0;    
for(int i=0; i < n;++i){
    tbl[i][i] = 0;
}

for(int l=2; l<n; ++l) // loop for size of chain
{
    for(int i=1; i <=n-l+1;++i) 
    {
	int j=i+l-1;
	tbl[i][j] = 999999;
	for(int k=i;k<j;++k)
	{
	    tbl[i][j] = min(tbl[i][j], tbl[i][k]+tbl[k+1][j]+ sz[i-1]*sz[k]*sz[j]);
	}
	cout << "\n filling order " << i<< " " <<j << endl;
    }
}

for(int i=0; i < n;++i){
    for(int j=0; j < n;++j) {
	cout << tbl[i][j] << " ";
    }
    cout << "\n";
}
return 0;
}
