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

int t, n, cs=1, i, comp, j;
vector<pair<double, ii> > edgeroad, edgerail;
vector<dd> cities;
double r, x, y, d, ansroad, ansrail;
vi p, size;

double dist(dd a, dd b)
{
	return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}
inline double rounding(double val)
{
	val*=1000.0;
	val+=0.5;
	ll temp=(ll)floor(val);
	return (double)temp/1000.0;
}
int findSet(int i)
{
	return p[i]==i?i:p[i]=findSet(p[i]);
}
void initSet(int n)
{
	p.assign(n, 0);
	size.assign(n, 1);
	for(i=0;i<n;++i)
		p[i]=i;
}
bool sameSet(int i, int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!sameSet(i, j))
	{
		size[findSet(j)]+=size[findSet(i)];
		p[findSet(i)]=p[findSet(j)];
	}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		cities.clear();
		scanf("%d %lf", &n, &r);
		for(i=1;i<=n;++i)
		{
			scanf("%lf %lf", &x, &y);
			cities.push_back(dd(x, y));
		}
		r=rounding(r);
		ansrail=ansroad=0.0;
		edgerail.clear();
		edgeroad.clear();
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				d=dist(cities[i], cities[j]);
				d=rounding(d);
				if(d<=r)
					edgeroad.push_back(make_pair(d, ii(i, j)));
				else
					edgerail.push_back(make_pair(d, ii(i, j)));
			}
		}
		p.clear();
		size.clear();
		initSet(n);
		sort(edgeroad.begin(), edgeroad.end());
		for(i=0;i<(int)edgeroad.size();++i)
		{
			pair<double, ii> temp=edgeroad[i];
			if(!sameSet(temp.second.first, temp.second.second))
			{
				unionSet(temp.second.first, temp.second.second);
				ansroad+=temp.first;
			}
		}
		comp=1;
		sort(edgerail.begin(), edgerail.end());
		for(i=0;i<(int)edgerail.size();++i)
		{
			pair<double, ii> temp=edgerail[i];
			if(!sameSet(temp.second.first, temp.second.second))
			{
				unionSet(temp.second.first, temp.second.second);
				ansrail+=temp.first;
				comp++;
			}
		}
		ansrail+=0.5;
		ansroad+=0.5;
		printf("Case #%d: %d %d %d\n",cs++, comp, (int)floor(ansroad), (int)floor(ansrail));
	}
	return 0;
}
