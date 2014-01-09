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

vector<vector<ii> > v;
vi visited, topo;
int n, m, x, y, i, j;

void dfs(int u)
{
	visited[u]=1;
	for(j=0;j<(int)v[u].size();++j)
	{
		ii temp=v[u][j];
		if(!visited[temp.first])
			dfs(temp.first);
	}
	topo.push_back(u);
}

int main()
{
	v.assign(101, vector<ii>());
	visited.assign(101, 0);
	while(true)
	{
		topo.clear();
		for(i=0;i<101;++i)
			visited[i]=0;
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		for(i=1;i<=n;++i)
			v[i].clear();
		while(m--)
		{
			scanf("%d %d", &x, &y);
			v[x].push_back(make_pair(y, 1));
		}
		for(i=1;i<=n;++i)
		{
			if(!visited[i])
				dfs(i);
		}
		reverse(topo.begin(), topo.end());
		for(i=0;i<n;++i)
		{
			if(i>0)
				putchar(' ');
			printf("%d", topo[i]);
		}
		putchar('\n');
	}
	return 0;
}
