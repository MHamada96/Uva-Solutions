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

int r, c, n, i, val, row, column, total;
int a[80];
map<int, vector<ii> > mp;
vector<ii> v;
ii temp;

int main()
{
	while(scanf("%d %d\n", &r, &c)!=EOF){
	row=0;
	mp.clear();
	while(true)
	{
		++row;
		if(row==r+1)
			break;
		scanf("%d", &n);
		if(n==0)
		{
			getchar();
			getchar();
		}
		else
		{
			for(i=0;i<n;++i)
				scanf("%d", &a[i]);
			for(i=0;i<n;++i)
			{
				scanf("%d", &val);
				mp[row].push_back(make_pair(a[i], val));
			}
		}
	}
	printf("%d %d\n", c, r);
	column=1;
	map<int, vector<ii> >::iterator it;
	while(column!=c+1)
	{
		it=mp.begin();
		v.clear();
		total=0;
		while(it!=mp.end())
		{
			if(!it->second.empty()){
			temp=it->second.front();
			if(temp.first==column)
			{
				++total;
				v.push_back(ii(it->first, temp.second));
				it->second.erase(it->second.begin(), it->second.begin()+1);
			}
			}
			++it;
		}
		printf("%d", total);
		if(!total)
			putchar('\n'), putchar('\n');
		else
		{
			for(i=0;i<(int)v.size();++i)
				printf(" %d", v[i].first);
			putchar('\n');
			for(i=0;i<(int)v.size();++i)
			{
				if(i>0)
					putchar(' ');
				printf("%d", v[i].second);
			}
			putchar('\n');
		}
		++column;
	}
	}
	return 0;
}
