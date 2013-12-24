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

ll n, i, a, b;
ll ans, sum;
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main()
{
	while(true)
	{
		scanf("%lld", &n);
		if(!n)
			break;
		ans=0;
		while(n--)
		{
			scanf("%lld", &sum);
			pq.push(sum);
		}
		sum=0;
		while(!pq.empty())
		{
			a=pq.top();
			pq.pop();
			if(pq.empty())
				break;
			b=pq.top();
			pq.pop();
			ans=a+b;
			sum+=ans;
			pq.push(ans);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
