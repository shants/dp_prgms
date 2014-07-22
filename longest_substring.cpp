#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
//string s1("photograph");
//string s2("tomography");

string s2("photograph");
string s1("tomography");

vector< vector<int> > tbl(s1.length(), vector<int>(s2.length(), 0));
for(int i=0; i<s1.length(); ++i)
{
    int j=0;
    if(s1[i] == s2[j])
	tbl[i][j] = 0;
}

for(int j=0; j<s2.length(); ++j)
{
    int i=0;
    if(s1[i] == s2[j])
	tbl[i][j] = 0;
}

for(int i=1; i < s1.length(); ++i)
{
    for(int j=1; j < s2.length(); ++j) 
    {
	if(s1[i] == s2[j])
	    tbl[i][j] = tbl[i-1][j-1] + 1;
	else
	{
	    tbl[i][j] =  0 ; //max(tbl[i-1][j], tbl[i][j-1]);
	}
    }
}


cout<<endl;
int max =0, x=0,y=0;
for(int i=0; i < s1.length(); ++i)
{
    for(int j=0; j < s2.length(); ++j) {
	cout << tbl[i][j] << " " ;
	if(max < tbl[i][j]) {
	    max = tbl[i][j];
	    x=j;
	    y = i;
	}
    }
    cout <<"\n";
}    
string str("");
cout << "\n ans is " << max  << " " << x << " " << y <<endl;
while(1){
    if(tbl[y][x] == 0)
	break;
    if(x > y)
    {
	str=s1[x] + str;
    }else{
	str=s2[y] + str;
    }
    x--;y--;
}
cout << "\n Ans " << str << endl;
return 0;
}
