// TOPCoder AVOIDROADS problem
//

// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include<string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class AvoidRoads
{
int a[50], b[50], c[50], d[50];
int p;
public:
	bool isOk(int fromI, int fromJ, int toI, int toJ) 
	{
		//unsigned int x=0;
		for (int x=0; x<p;x++) {
		if( ((fromI==a[x]) && (fromJ == b[x]) && (toI == c[x]) && (toJ == d[x])) ||
			((toI==a[x]) && (toJ == b[x]) && (fromI == c[x]) && (fromJ == d[x])) )
			return false;
		}
		return true;
	}

	long long numWays(int width, int height, vector <string> bad)
	{
		memset(&a, 0, 50);
		memset(&b, 0, 50);
		memset(&c, 0, 50);
		memset(&d, 0, 50);
		p = (int)bad.size();

		long long S[101][101];// = {0};
		for(int i=0; i<101; ++i) {
			for(int j=0; j<101; ++j) {
				S[i][j] = 0;
			}
		}
		S[0][0] = 1;
		for(int i=0; i < (int)bad.size(); ++i) {
			string str = bad[i];
			istringstream iss(str);
			int a1,b1,c1,d1;
			while(iss >> a1 >>b1 >> c1 >>d1){
				cout << "found entry " << a1<< " " << b1 << " " << c1 <<" "<<d1 <<"\n";
				a[i]=a1;
				b[i]=b1;
				c[i]=c1;
				d[i]=d1;
			}
		}
		
		for(int i=0; i<=width; ++i) {
			for(int j=0; j<=height;++j) {
				if(i>0) {
					if(isOk(i, j, i-1, j)) {
						S[i][j]  += S[i-1][j];
					}
				}
				if(j>0) {
					if(isOk(i, j, i, j-1)) {
						S[i][j] += S[i][j-1];
					}
				}
			}
			cout << endl;
		}

		for(int i=0; i <=width;++i){
		    for(int j=0; j <= height;++j) {
			//cout << S[i][j] <<" " ;
		    }
		    cout << endl;
		}
		return S[width][height];
	}
};
#if 0
int main() {
vector<string> s;
s.push_back("0 0 1 0");
s.push_back("6 6 5 6");

AvoidRoads av;
 cout << av.numWays(1,1,s);

return 0;
}
#endif 
