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

int n, i, ans, stud;
map<ll, int> mp;
int a[6];
ll num;

int main()
{
	while(true)
	{
		scanf("%d", &n);
		if(!n)
			break;
		mp.clear();
		ans=1;
		stud=0;
		while(n--)
		{
			scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
			sort(a, a+5);
			num=0;
			i=0;
			while(i!=5)
				num=(ll)num*1000+(ll)a[i++];
			if(mp.count(num)==0)
			{
				mp[num]=1;
			}
			else
			{
				mp[num]+=1;
				if(mp[num]>ans)
					ans=mp[num];
			}
		}
		map<ll, int>::iterator it;
		it=mp.begin();
		while(it!=mp.end())
		{
			if(it->second==ans)
				stud+=ans;
			++it;
		}
		printf("%d\n", stud);
	}
	return 0;
}
