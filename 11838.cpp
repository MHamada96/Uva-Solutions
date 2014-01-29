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

vector<vector<ii> > adj;
vi visited, low, num, S;
int n, m, x, y, counter, ans, p, i;

void Tarjan(int u)
{
	visited[u]=1;
	low[u]=num[u]=counter++;
	S.push_back(u);
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(num[v.first]==-1)
			Tarjan(v.first);
		if(visited[v.first])
			low[u]=min(low[u], low[v.first]);
	}
	if(low[u]==num[u])
	{
		++ans;
		while(1)
		{
			int v=S.back();
			S.pop_back();
			visited[v]=0;
			if(u==v)
				break;
		}
	}
}
int main()
{
	adj.assign(2001, vector<ii>());
	low.assign(2001, 0);
	num.assign(2001, 0);
	visited.assign(2001, 0);
	while(true)
	{
		counter=ans=0;
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		for(i=1;i<=n;++i)
			adj[i].clear(), num[i]=-1, low[i]=visited[i]=0;
		S.clear();
		while(m--)
		{
			scanf("%d %d %d", &x, &y, &p);
			adj[x].push_back(make_pair(y, 1));
			if(p==2)
				adj[y].push_back(make_pair(x, 1));
		}
		for(i=1;i<=n;++i)
			if(num[i]==-1)
				Tarjan(i);
		if(ans==1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
