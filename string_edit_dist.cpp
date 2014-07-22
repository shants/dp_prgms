#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define INS 1
#define DEL 1
#define REP 2

int main()
{
string s1, s2;
string ss1, ss2;

cout<< "\n Give first string";
cin>>s1;
cout << "\n give second string";
cin>> s2;
int l1 = (int)s1.length();
int l2 = (int)s2.length();
int row = l1+1;
int col = l2+1;
ss1 = " " + s1; ss2 = " " + s2;
vector< vector<int> > tbl(row, vector<int>(col,0));
for(int i=0; i < row; ++i) {
tbl[i][0] = i;
}

for(int j=0; j < col; ++j) {
tbl[0][j] = j;
}

int i=0, j=0;
for(i=1; i < row; ++i) {
    for(j=1; j<col; ++j) {
	if(ss1[i]==ss2[j]) {
	    tbl[i][j] = tbl[i-1][j-1];
	}else{
	    int c1 = tbl[i-1][j-1] + REP;
	    int c2 = tbl[i-1][j] + DEL;
	    int c3 = tbl[i][j-1] + INS;
	    tbl[i][j] = min({c1, c2, c3});
	}
    }
}

cout << "\n ans is " << tbl[row-1][col-1] << "\n";
return 0;
}

