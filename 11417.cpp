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

int n, i, j;
ll ans;
map<int, ll> mp;

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		if(mp.count(n)!=0)
		{
			printf("%lld\n", mp[n]);
			continue;
		}
		ans=0;
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j)
				ans+=gcd(i, j);
		printf("%lld\n", ans);
		mp[n]=ans;
	}
	return 0;
}
