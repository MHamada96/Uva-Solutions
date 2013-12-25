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
int a[100010];

int main()
{
	v.assign(1000005, vector<int>());
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		v.clear();
		for(pos=1;pos<=n;++pos)
		{
			scanf("%d", &val);
			a[pos]=val;
			v[val].push_back(pos);
		}
		while(m--)
		{
			scanf("%d %d", &k, &val);
			if(v[val].size()<k)
				printf("0\n");
			else
				printf("%d\n", v[val][k-1]);
		}
		for(pos=1;pos<=n;++pos)
			v[a[pos]].clear();
	}
	return 0;
}
