#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>

 using namespace std;

#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int n, i;
map<string, int> mp;
char s[77];
string x;

int main()
{
	mp.clear();
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(s);
		x="";
		for(i=0;i<(int)strlen(s);++i)
			if(s[i]==' ')
				break;
			else
				x+=s[i];
		if(mp.count(x)==0)
			mp[x]=1;
		else
			mp[x]+=1;
	}
	map<string, int>::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<it->first;
		printf(" %d\n", it->second);
		++it;
	}
	return 0;
}
