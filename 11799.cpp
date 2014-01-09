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

int t, n, ans, val, cs=1;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans=-INF;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &val);
			if(val>ans)
				ans=val;
		}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}
