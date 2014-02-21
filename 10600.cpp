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

int t, n, m, a, b, c, s1, s2, tot, i, j, numDisjointSet, bestdis;
vector<pair<int, ii> > edge;
vector<ii> best;
vi p;

int findSet(int i)
{
	return p[i]==i?i:p[i]=findSet(p[i]);
}
bool sameSet(int i, int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!sameSet(i, j))
	{
		numDisjointSet--;
		p[findSet(i)]=p[findSet(j)];
	}
}
void initSet(int n)
{
	p.assign(n+1, 0);
	for(i=1;i<=n;++i)
		p[i]=i;
	numDisjointSet=n;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		edge.clear();
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			edge.push_back(make_pair(c, ii(a, b)));
		}
		sort(edge.begin(), edge.end());
		p.clear();
		initSet(n);
		best.clear();
		s1=0;
		s2=INF;
		for(i=0;i<(int)edge.size();++i)
		{
			pair<int, ii> temp=edge[i];
			if(!sameSet(temp.second.first, temp.second.second))
			{
				unionSet(temp.second.first, temp.second.second);
				s1+=temp.first;
				best.push_back(ii(temp.second.first, temp.second.second));
			}
		}
		bestdis=numDisjointSet;
		for(j=0;j<(int)best.size();++j)
		{
			ii e=best[j];
			p.clear();
			initSet(n);
			tot=0;
			for(i=0;i<(int)edge.size();++i)
			{
				pair<int, ii> temp=edge[i];
				if(min(temp.second.first, temp.second.second)!=min(e.first, e.second) || max(temp.second.first, temp.second.second)!=max(e.first, e.second))
				if(!sameSet(temp.second.first, temp.second.second))
				{
					unionSet(temp.second.first, temp.second.second);
					tot+=temp.first;
				}
			}
			if(numDisjointSet==bestdis)
				s2=min(s2, tot);
		}
		printf("%d %d\n", s1, s2);
	}
	return 0;
}
