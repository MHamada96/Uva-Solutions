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

int n, m, i, x, y, counter;
vector<vector<ii> > adj;
vi visited, topo, com;
bool ans=false;

void dfs(int u)
{
	visited[u]=1;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii temp=adj[u][j];
		if(visited[temp.first]==0)
			dfs(temp.first);
		else
		if(visited[temp.first]==1)
			ans=false;
	}
	visited[u]=2;
	topo.push_back(u);
}
int main()
{
	st=clock();
	adj.assign(1000001, vector<ii>());
	visited.assign(1000001, 0);	
	com.assign(1000001, 0);	
	while(true)
	{
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		counter=1;
		ans=true;
		topo.clear();
		for(i=1;i<=n;++i)
			adj[i].clear();
		while(m--)
		{
			scanf("%d %d", &x, &y);
			adj[x].push_back(make_pair(y, 1));
		}
		for(i=1;i<=n;++i)
			visited[i]=0, com[i]=0;
		for(i=1;i<=n;++i)
			if(visited[i]==0)
				dfs(i);
		reverse(topo.begin(), topo.end());
		if(ans)
			for(i=0;i<(int)topo.size();++i)
				printf("%d\n", topo[i]);
		else
			puts("IMPOSSIBLE");
	}

	ed=clock();
	if(tme)
		printf("Execution time: %.3lf\n", (double)(ed-st)/CLOCKS_PER_SEC);
	return 0;
}
