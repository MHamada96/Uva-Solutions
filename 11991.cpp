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

int n, m, num, k, val, pos;
vector<vector<int> > v;
map<int, vector<int> > mp;

int main()
{
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		mp.clear();
		for(pos=1;pos<=n;++pos)
		{
			scanf("%d", &val);
			mp[val].push_back(pos);
		}
		while(m--)
		{
			scanf("%d %d", &k, &val);
			if(mp.count(val)==0)
				printf("0\n");
			else
			if(mp[val].size()<k)
				printf("0\n");
			else
			printf("%d\n", mp[val][k-1]);
		}
	}
	return 0;
}
