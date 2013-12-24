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

int pp, g, flag, correct=0, cs=1;
char s[10101], *p, sign[10];
map<string, double> mp;
double val, ans, n;

double round(double n)
{
	n*=10.0;
	n+=0.5;
	int x;
	x=(int)floor(n);
	return (double)x/10.0;
}
int main()
{
	scanf("%d %d", &pp, &g);
	while(pp--)
	{
		scanf("%s %lf\n", s, &val);
		mp[s]=val;
	}
	while(g--)
	{
		ans=0.0;
		flag=0;
		correct=0;
		gets(s);
		for(p=strtok(s, " ");p;p=strtok(NULL, " "))
		{
			if(flag==1)
			{
				if(strcmp(p, "+")==0)
					flag=0;
				else
				{
					flag=2;
					strcpy(sign, p);
				}
			}
			else
			if(flag==0)
			{
				flag=1;
				ans+=(mp[p]);
			}
			else
			if(flag==2)
			{
				ans=round(ans);
				n=(double)atoi(p);
				n=round(n);
				if(strcmp(sign, "<")==0 && ans<n)
					correct=1;
				if(strcmp(sign, "<=")==0 && ans<=n)
					correct=1;
				if(strcmp(sign, ">")==0 && ans>n)
					correct=1;
				if(strcmp(sign, ">=")==0 && ans>=n)
					correct=1;
				if(strcmp(sign, "=")==0 && ans==n)
					correct=1;
			}
		}
		if(correct)
			printf("Guess #%d was correct.\n", cs++);
		else
			printf("Guess #%d was incorrect.\n", cs++);
	}
	return 0;
}
