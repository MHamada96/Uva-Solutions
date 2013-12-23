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

int r, c, m, n, t, cs=1, i, j, ans, *mx;
int frequency[33];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans=0;
		memset(frequency, 0, sizeof frequency);
		scanf("%d %d %d %d", &r, &c, &m, &n);
		getchar();
		for(i=0;i<r;++i)
		{
			for(j=0;j<c;++j)
			{
				frequency[getchar()-65]++;
			}
			getchar();
		}
		mx=max_element(frequency, frequency+26);
		for(i=0;i<26;++i)
		{
			if(frequency[i]!=0)
			{
				if(frequency[i]!=*mx)
					ans+=(n*frequency[i]);
				else
					ans+=(m*frequency[i]);
			}
		}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}
