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
#include <ctime>

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

clock_t st, ed;
bool tme=false;

int t, n, m, l, ans, x, y, i;
vector<vector<ii> > adj;
vi visited;

int dfs(int u)
{
	++ans;
	visited[u]=1;
	int len=(int)adj[u].size();
	for(int j=0;j<len;++j)
	{
		ii temp=adj[u][j];
		if(!visited[temp.first])
			dfs(temp.first);
	}
	if(len==0)
		return 1;
}
int main()
{
	st=clock();
	adj.assign(100001, vector<ii>());
	visited.assign(100001, 0);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &l);
		visited.clear();
		for(i=1;i<=n;++i)
			visited[i]=0;
		adj.clear();
		for(i=1;i<=n;++i)
			adj[i].clear();
		while(m--)
		{
			scanf("%d %d", &x, &y);
			adj[x].push_back(make_pair(y, 1));
		}
		ans=0;
		while(l--)
		{
			scanf("%d", &x);
			if(!visited[x])
				dfs(x);
		}
		printf("%d\n", ans);
	}
	return 0;
	ed=clock();
	if(tme)
		printf("Execution time: %.3lf\n", (double)(ed-st)/CLOCKS_PER_SEC);
}
