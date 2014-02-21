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

int n, m, u, v, w, i, j, numOfDisjoint;
vector<pair<int, ii> > edges;
set<int> ans;
vi p, size;
bool flag;


void initSet(int n)
{
	size.assign(n, 1);
	p.assign(n, 0);
	for(i=0;i<n;++i)
		p[i]=i;
	numOfDisjoint=n;
}
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
		numOfDisjoint--;
		size[findSet(j)]+=size[findSet(i)];
		p[findSet(i)]=p[findSet(j)];
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d", &n, &m);
		ans.clear();
		edges.clear();
		size.clear();
		p.clear();
		if(!n && !m)
			break;
		initSet(n);
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, ii(u, v)));
		}
		sort(edges.begin(), edges.end());
		for(i=0;i<(int)edges.size();++i)
		{
			pair<int, ii> temp=edges[i];
			if(!sameSet(temp.second.first, temp.second.second))
				unionSet(temp.second.first, temp.second.second);
			else
				ans.insert(temp.first);
		}
		flag=false;
		if(ans.size()==0)
			printf("forest");
		else
		{
			set<int>::iterator it=ans.begin();
			while(it!=ans.end())
			{
				if(flag)
					putchar(' ');
				flag=true;
				printf("%d", *it++);
			}
		}
		putchar('\n');
	}
	return 0;
}
