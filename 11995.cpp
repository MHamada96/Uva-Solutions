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

int n, a, b;
stack<int> st;
queue<int> q;
priority_queue<int> pq;
int stck, qu, prq;

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		st=stack<int>();
		q=queue<int>();
		pq=priority_queue<int>();
		stck=qu=prq=1;
		while(n--)
		{
			scanf("%d %d", &a, &b);
			if(a==1)
			{
				st.push(b);
				pq.push(b);
				q.push(b);
			}
			if(a==2)
			{
				if(!st.empty()){
				if(st.top()!=b)
					stck=0;}
				else
					stck=0;
				if(!pq.empty()){
				if(pq.top()!=b)
					prq=0;}
				else
					prq=0;
				if(!q.empty()){
				if(q.front()!=b)
					qu=0;}
				else
					qu=0;
				if(!st.empty())
					st.pop();
				if(!pq.empty())
					pq.pop();
				if(!q.empty())
					q.pop();
			}
		}
		if(stck==1 && qu==0 && prq==0)
			puts("stack");
		else
		if(stck==0 && qu==1 && prq==0)
			puts("queue");
		else 
		if(stck==0 && qu==0 && prq==1)
			puts("priority queue");
		else
		if(stck==0 && qu==0 && prq==0)
			puts("impossible");
		else
			puts("not sure");
	}
	return 0;
}
