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

int n, m, ans, cs=1, i, a, b;
vi p;

void initSet(int n)
{
    ans=n-1;
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
    p.clear();
    p.assign(111111, 0);
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(!n && !m)
            break;
        initSet(n+1);
        while(m--)
        {
            scanf("%d %d", &a, &b);
            Union(a, b);
        }
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
