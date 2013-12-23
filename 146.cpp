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

char s[55];
int len, i, flag;

int main()
{
	while(true)
	{
		scanf("%s", s);
		flag=0;
		if(strcmp(s, "#")==0)
			break;
		len=(int)strlen(s);
		for(i=1;i<len;++i)
			if(s[i]>s[i-1])
			{
				flag=1;
				break;
			}
		if(flag)
		{
			next_permutation(s, s+len);
			for(i=0;i<len;++i)
				putchar(s[i]);
			putchar('\n');
		}
		else
		{
			puts("No Successor");
		}
	}
	return 0;
}
