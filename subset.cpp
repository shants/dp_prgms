#include<iostream>
#include<vector>

using namespace std;

int main()
{
int arr[] = { 1,1,3,4,5 };
int total = 0;
vector<int> v(arr, arr+(sizeof(arr)/sizeof(int)));
	    int nu = arr[0];
	    v[0] = 0;
	    v.push_back(nu);
for(auto x : v ){
    cout << "\t "<<x;
    total+=x;
}

cout<<"\n";
int row = 5;
int col = total;
vector< vector<int> > subset(row+1, vector<int>(total+1, 0) );

for(int j=0; j <= col; ++j)
    subset[0][j] = 0; 

for(int i=0; i <= row; ++i)
    subset[i][0] = 1;

for(int i=1; i <=row; ++i)
{
    for(int j=1; j <=col; ++j)
    {
	subset[i][j] = subset[i-1][j] || ( (v[i]<=j) && subset[i-1][j-v[i]] );
    }
}

for(int k=0; k <=row; ++k)
{
    for(int l=0; l <=col; ++l){
	cout<< " " << subset[k][l];
    }
    cout<<"\n";
}

cout <<  "\n give the number k \n";
int k;
cin>>k;

int j = k;
int i=row;
while(i>=1){
if(subset[i-1][j] == 0){
    cout<< v[i] << "added to set \n";
    j = j-v[i];
    }
    i--;//j = j-v[i];
}
return 0;
}
