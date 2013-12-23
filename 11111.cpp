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

vi v;
stack<int> st;
char s[10000010], *p;
int a[10000010];
int i, n, tmp, sum;
bool ans=true;

int main()
{
	while(scanf("%d", &tmp)!=EOF)
	{
		v.clear();
		st=stack<int>();
		gets(s);
		a[1]=tmp;
		i=2;
		for(p=strtok(s, " ");p;p=strtok(NULL, " "))
			a[i++]=atoi(p);
		n=i;
		ans=true;
		if(a[1]>0)
			ans=false;
		st.push(a[1]);
		if(ans)
		{
			sum=0;
			for(i=2;i<n;++i)
			{
				if(a[i]<0)
				{
					v.push_back(sum);
					sum=0;
					st.push(a[i]);
				}
				else
				{
					tmp=st.top();
					st.pop();
					if(abs(tmp)!=a[i])
					{
						ans=false;
						break;
					}
					if(a[i]<=sum)
					{
						ans=false;
						break;
					}
					if(!v.empty())
					{
						sum=v.back();
						v.pop_back();
					}
					sum+=a[i];
				}
			}
		}
		if(!st.empty())
			ans=false;
		if(ans)
			printf(":-) Matrioshka!\n");
		else
			printf(":-( Try again.\n");
	}
	return 0;
}
