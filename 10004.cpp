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

int n, l, x, y, i, u;
vector<vector<ii> > v;
queue<int> q;
map<int, int> dist;
bool ans;
ii temp;

int main()
{
	v.assign(222, vector<ii>());
	while(true)
	{
		ans=true;
		scanf("%d", &n);
		if(!n)
			break;
		for(i=0;i<n;++i)
			v[i].clear();
		dist.clear();
		q=queue<int>();
		scanf("%d", &l);
		while(l--)
		{
			scanf("%d %d", &x, &y);
			v[x].push_back(make_pair(y, 1));
			v[y].push_back(make_pair(x, 1));
		}
		q.push(0);
		dist[0]=0;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(i=0;i<(int)v[u].size();++i)
			{
				temp=v[u][i];
				if(!dist.count(temp.first))
					dist[temp.first]=1-dist[u], q.push(temp.first);
				else
					if(dist[temp.first]==dist[u])
						ans=false;
			}
		}
		if(ans)
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	return 0;
}
