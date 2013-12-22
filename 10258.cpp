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

bool flag=false;
int t, num, prob, tim, i;
char status;
char s[100];
struct Contestant
{
	int number, penalty, solved;
	bool submitted;
	int problems[10], incorrect_penalty[10];
	Contestant(){
		number=0;
		submitted=false;
		solved=0;
		penalty=0;
		memset(problems, 0, sizeof problems);
	};
	Contestant(int n)
	{
		number=n;
		penalty=solved=0;
		submitted=true;
		memset(problems, 0, sizeof problems);
		memset(incorrect_penalty, 0, sizeof incorrect_penalty);
	}
};

bool cmp(Contestant a, Contestant b)
{
	if(a.solved!=b.solved)
		return a.solved>b.solved;
	if(a.penalty!=b.penalty)
		return a.penalty<b.penalty;
	return a.number<b.number;
}

int main()
{
	scanf("%d", &t);
	getchar();
	getchar();
	while(t--)
	{
		Contestant rank[111];
		if(t!=0)
		while(true)
		{
			gets(s);
			if(strcmp(s, "")==0)
				break;
			sscanf(s, "%d %d %d %c", &num, &prob, &tim, &status);
			Contestant temp(num);
			if(rank[num].number!=num)
				rank[num]=temp;
			if(status=='C' && !rank[num].problems[prob])
			{
				rank[num].penalty+=tim+rank[num].incorrect_penalty[prob];
				rank[num].solved+=1;
				rank[num].problems[prob]=1;
			}
			if(status=='I')
			{
				rank[num].incorrect_penalty[prob]+=20;
			}
		}
		if(t==0)
		{
			while(scanf("%d %d %d %c", &num, &prob, &tim, &status)!=EOF)
			{
				Contestant temp(num);
				if(rank[num].number!=num)
					rank[num]=temp;
				if(status=='C' && !rank[num].problems[prob])
				{
					rank[num].penalty+=tim+rank[num].incorrect_penalty[prob];
					rank[num].solved+=1;
					rank[num].problems[prob]=1;
				}
				if(status=='I')
				{
					rank[num].incorrect_penalty[prob]+=20;
				}
			}		
		}
		if(flag)
			putchar('\n');
		flag=true;
		sort(rank+1, rank+101, cmp);
		for(i=1;i<=100;++i)
		{
			if(rank[i].submitted)
			{
				printf("%d %d %d\n", rank[i].number, rank[i].solved, rank[i].penalty);
			}
		}
	}
	return 0;
}
