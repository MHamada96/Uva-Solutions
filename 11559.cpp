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

int n, b, h, w, p, x, ans, cnt, can;

int main()
{
	while(scanf("%d %d %d %d", &n, &b, &h, &w)!=EOF)
	{
		ans=INF;
		while(h--)
		{
			can=0;
			scanf("%d", &p);
			cnt=w;
			while(cnt--)
			{
				scanf("%d", &x);
				if(x>=n)
					can=1;
			}
			if(can && p*n<ans && p*n<=b)
				ans=p*n;
		}
		if(ans!=INF)
			printf("%d\n", ans);
		else
			puts("stay home");
	}
	return 0;
}
