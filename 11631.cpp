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

int m, n, numOfDisjoint, num, i, total, ans, x, y, z;
vector<pair<int, ii> > edge;
vi p, size;

void initSet(int N)
{
	size.assign(N+1, 1);
	p.assign(N+1, 0);
	for(i=1;i<=N;++i)
		p[i]=i;
	numOfDisjoint=N;
}
int findSet(int i)
{
	return p[i]==i?i:p[i]=findSet(p[i]);
}
bool isSameSet(int i, int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!isSameSet(i, j))
	{
		numOfDisjoint--;
		size[findSet(j)]+=size[findSet(i)];
		p[findSet(i)]=p[findSet(j)];
	}
}
int main()
{
	while(true)
	{
		scanf("%d %d", &m, &n);
		if(!m && !n)
			break;
		total=ans=0;
		edge.clear();
		p.clear();
		size.clear();
		initSet(m);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d", &x, &y, &z);
			total+=z;
			edge.push_back(make_pair(z, make_pair(x+1, y+1)));
		}
		sort(edge.begin(), edge.end());
		num=0;
		for(i=0;i<n;++i)
		{
			pair<int, ii> temp=edge[i];
			if(!isSameSet(temp.second.first, temp.second.second))
			{
				ans+=temp.first;
				unionSet(temp.second.first, temp.second.second);
				++num;
				if(num==m-1)
					break;
			}
		}
		printf("%d\n", total-ans);
	}
	return 0;
}
