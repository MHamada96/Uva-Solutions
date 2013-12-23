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

int t, s, a, f, street, avenue, x, y, i;
int str[1010], aven[1010];
int sumstr[1010], sumaven[1010];

int binary(int a[], int s)
{
	int low=1, high=1000, center;
	int ans;
	while(low<=high)
	{
		center=(low+high)/2;
		if(a[center]>=s)
			ans=center, high=center-1;
		if(a[center]<s)
			low=center+1;
	}
	return ans;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &s, &a, &f);
		memset(str, 0, sizeof str);
		memset(aven, 0, sizeof aven);
		for(i=0;i<f;++i)
		{
			scanf("%d %d", &x, &y);
			str[x]++;
			aven[y]++;
		}
		sumstr[1]=str[1];
		sumaven[1]=aven[1];
		for(i=2;i<=1000;++i)
		{
			sumstr[i]=str[i]+sumstr[i-1];
			sumaven[i]=aven[i]+sumaven[i-1];
		}
		s=f/2;
		if(f%2!=0)
			++s;
		street=binary(sumstr, s);
		avenue=binary(sumaven, s);
		printf("(Street: %d, Avenue: %d)\n", street, avenue);
	}
	return 0;
}
