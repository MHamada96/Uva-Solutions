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
#include <ctime>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, ans, i;
char a, b;
vi p;
bool blank=false;

void initSet(int n)
{
    ans=n;
    for(i=1;i<=n;++i)
        p[i]=i;
}

int findSet(int i)
{
    return (p[i]==i)?i:p[i]=findSet(p[i]);
}

bool sameSet(int i, int j)
{
    return findSet(i)==findSet(j);
}

void Union(int i, int j)
{
    if(!sameSet(i, j))
    {
        p[findSet(i)]=p[findSet(j)];
        --ans;
    }
}

int main()
{
    scanf("%d", &t);
    getchar();
    getchar();
    p.clear();
    p.assign(3333, 0);
    while(t--)
    {
        a=getchar();
        getchar();
        initSet(a-64);
        while(scanf("%c", &a)!=EOF)
        {
            if(a=='\n')
                break;
            b=getchar();
            getchar();
            Union(a-64, b-64);
        }
        if(blank)
            putchar('\n');
        blank=true;
        printf("%d\n", ans);
    }
    return 0;
}
