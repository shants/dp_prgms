/*
solution to : http://community.topcoder.com/tc?module=ProblemDetail&rd=4630&pm=1861
Problem Name:	ShortPalindromes 
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;
#define INF 9999
class min2palin
{

public :
	int calc(string s) 
	{
		int res = -1;
		int table [50][50] = { INF };
		int sz = (int)s.length();
		for(int i=0; i<sz; ++i) 
		{
			table[i][i] = 0;
		}
		for(int gap =1; gap < sz;++gap)
		{
			for(int i=0; i<sz; ++i) 
			{
				for(int j=i+1; ((j<=i+gap) && (j < sz)) ; ++j)
				{
					if(s[i] == s[j]) 
					{
						table[i][j] = table[i+1][j-1];
					}
					else
					{
						table[i][j] = 1 + min(table[i+1][j], table[i][j-1]);
					}
				}
			}
		}	
		
		for(int i=0 ; i <sz ; ++i) {
			for(int ji=0 ; ji <sz ; ++ji) {
				cout << table[i][ji] << " ";
			}
			cout << endl;
		}

		return table[0][sz-1];
	}


};



int main()
{
min2palin m;
cout << "\n " << m.calc("CAR") << endl;

return 0;
}
