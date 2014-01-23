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

struct ans
{
	int a, b;
};
int n, u, v, l, i, cou, counter;
vector<vector<ii> > adj;
vi low, num, parent;
ans obj[100001];
bool cmp(ans X, ans Y)
{
	if(X.a!=Y.a)
		return X.a<Y.a;
	return X.b<Y.b;
}
void articulation_point(int u)
{
	low[u]=num[u]=counter++;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(num[v.first]==-1)
		{
			parent[v.first]=u;
			articulation_point(v.first);
			if(low[v.first]>num[u])
				obj[cou].a=min(u, v.first), obj[cou++].b=max(v.first, u);
			low[u]=min(low[u], low[v.first]);
		}
		else
		if(parent[u]!=v.first)
			low[u]=min(low[u], num[v.first]);
	}
}

int main()
{
	adj.assign(100001, vector<ii>());
	low.assign(100001, 0);
	num.assign(100001, 0);
	parent.assign(100001, 0);
	while(scanf("%d", &n)!=EOF)
	{
		cou=counter=0;
		for(i=1;i<=n;++i)
			num[i]=-1,low[i]=parent[i]=0, adj[i].clear();
		for(i=1;i<=n;++i)
		{
			scanf("%d (%d)", &u, &l);
			++u;
			while(l--)
			{
				scanf("%d", &v);
				++v;
				adj[u].push_back(make_pair(v, 1));
				adj[v].push_back(make_pair(u, 1));
			}
		}
		for(i=1;i<=n;++i)
		{
			if(num[i]==-1)
				articulation_point(i);
		}
		sort(obj, obj+cou, cmp);
		printf("%d critical links\n", cou);
		for(i=0;i<cou;++i)
			printf("%d - %d\n", obj[i].a-1, obj[i].b-1);
		putchar('\n');
	}
	return 0;
}
