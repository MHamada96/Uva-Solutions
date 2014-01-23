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

int n, r, root, children, i, counter, total, cs=1;
vector<vector<ii> > adj;
vi low, num, parent, articulation;
map<string, int> mp;
map<int, string> rev;
char a[33], b[33];
vector<string> ans;
bool blank=false;

void articulation_point(int u)
{
	low[u]=num[u]=counter++;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(num[v.first]==-1)
		{
			parent[v.first]=u;
			if(u==root)
				children++;
			articulation_point(v.first);
			if(low[v.first]>=num[u])
				articulation[u]=1;
			low[u]=min(low[u], low[v.first]);
		}
		else
		if(parent[u]!=v.first)
			low[u]=min(low[u], num[v.first]);
	}
}
int main()
{
	adj.assign(111, vector<ii>());
	low.assign(111, 0);
	num.assign(111, 0);
	articulation.assign(111, 0);
	parent.assign(111, 0);
	while(true)
	{
		scanf("%d", &n);
		if(!n)
			break;
		counter=0;
		ans.clear();
		for(i=1;i<=n;++i)
		{
			scanf("%s", a);
			mp[a]=i;
			rev[i]=a;
			num[i]=-1;
			low[i]=articulation[i]=parent[i]=0;
			adj[i].clear();
		}
		scanf("%d", &r);
		while(r--)
		{
			scanf("%s %s", a, b);
			adj[mp[a]].push_back(make_pair(mp[b], 1));
			adj[mp[b]].push_back(make_pair(mp[a], 1));
		}
		for(i=1;i<=n;++i)
			if(num[i]==-1)
			{
				root=i;
				children=0;
				articulation_point(i);
				articulation[i]=(children>1);
			}
		total=0;
		if(blank)
			putchar('\n');
		blank=true;
		for(i=1;i<=n;++i)
			if(articulation[i])
				ans.push_back(rev[i]), ++total;
		sort(ans.begin(), ans.end());
		printf("City map #%d: %d camera(s) found\n", cs++, total);
		for(i=0;i<(int)ans.size();++i)
			cout<<ans[i]<<endl;
	}
	return 0;
}
