#include<iostream>
#include<vector>
#include<string>
// chocolate
// chips
// cchocohilaptes
using namespace std;

int main()
{
#if 0
string s1("chocolate");
string s2("chips");
//string s3("cchocohilaptes");
string s3("chocochilatspe");
#endif
string s1("ch");
string s2("ca");
string s3("ccha");
vector< vector<int> > tbl(s1.length(), vector<int>(s2.length(), 0));

for(int i=0; i<s1.length(); ++i) {
    int j=0; 
   if(s3[i+j] == s1[i])
	tbl[i][j] = 1;
}


for(int j=0; j<s2.length(); ++j) {
    int i=0; 
   if(s3[i+j] == s2[j])
	tbl[i][j] = 1;
}

if( ((s3[1]==s1[0]) && (s3[0]==s2[0])) || ((s3[1]==s1[0])&&(s3[0]==s2[0])))
    tbl[1][1] = 1;

for(int i=1; i < s1.length(); ++i)
{
    for(int j=1; j < s2.length(); ++j) 
    {
	if(i==1 && j==1) 
	    continue;
	if((s3[i+j-1] == s2[j-1] && tbl[i][j-1] ==1) || 
		(s3[i+j-1] == s1[i-1] && tbl[i-1][j] ==1))
	{
	    tbl[i][j] =1;
	}
    } 
}

for(int i=0; i < s1.length(); ++i)
{
    for(int j=0; j < s2.length(); ++j)
    {
	cout <<tbl[i][j] << " " ;
    }
    cout << "\n";
}

cout << "\n ans is " << tbl[s1.length()-1][s2.length() -1];
return 0;
}

