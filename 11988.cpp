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

char s[1000100];
int len, i;
bool lin=false, chain=false, first=false, sec=false, ex=false;

struct Node
{
	char ch;
	Node *next;
}*st, *en, *ptr, *tmp, *st2;

int main()
{
	while(scanf("%s", s)!=EOF)
	{
		len=(int)strlen(s);
		st=en=NULL;
		lin=chain=first=sec=ex=false;
		for(i=0;i<len;++i)
		{
			if(s[i]!='[' && s[i]!=']' && !chain)
			{
				if(!first)
				{
					ptr=new Node;
					ptr->ch=s[i];
					ptr->next=NULL;
					st=en=ptr;
					first=true;
				}
				else
				{
					ptr=new Node;
					ptr->ch=s[i];
					ptr->next=NULL;
					en->next=ptr;
					en=ptr;
				}
				ex=true;
			}
			if(s[i]=='[')
			{
				if(lin && ex)
				{
					tmp->next=st;
					st=st2;
				}
				if(lin && !ex)
				{
					st=st2;
					en=tmp;
					ex=true;
					first=true;
				}
				lin=false;
				sec=false;
				chain=true;
			}
			if(s[i]==']')
			{
				chain=false;
				if(lin && ex)
				{
					tmp->next=st;
					st=st2;
				}
				if(lin && !ex)
				{
					st=st2;
					en=tmp;
					ex=true;
					first=true;
				}
				lin=false;
				sec=false;
			}
			if(s[i]!='[' && s[i]!=']' && chain)
			{
				ptr=new Node;
				ptr->ch=s[i];
				ptr->next=NULL;
				if(!sec)
				{
					st2=tmp=ptr;
					sec=true;
				}
				else
				{
					tmp->next=ptr;
					tmp=ptr;
				}
				lin=true;
			}
		}
		if(lin)
		{
			tmp->next=st;
			st=st2;
		}
		while(st!=NULL)
		{
			printf("%c", st->ch);
			tmp=st;
			st=st->next;
			delete tmp;
		}
		putchar('\n');
	}
	return 0;
}
