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

int t, cnt, f, x, y;
map<string, int> mp;
char a[22], b[22];
vi id(200000), sz(200000);

int find(int i)
{
	return (id[i]==i)?i:id[i]=find(id[i]);
}
bool isSame(int i, int j)
{
	return find(i)==find(j);
}
void join(int i, int j)
{
	if(!isSame(i, j))
	{
		sz[find(j)]+=sz[find(i)];
		id[find(i)]=find(j);
	}
}
int size(int i)
{
	return sz[find(i)];
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &f);
		cnt=1;
		mp.clear();
		sz.assign(2*f+1, 1);
		while(f--)
		{
			scanf("%s %s", a, b);
			if(mp.count(a)==0)
				mp[a]=cnt++, id[mp[a]]=cnt-1;
			if(mp.count(b)==0)
				mp[b]=cnt++, id[mp[b]]=cnt-1;
			x=mp[a];
			y=mp[b];
			join(x, y);
			printf("%d\n", size(x));
		}
	}
	return 0;
}
