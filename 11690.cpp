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

int n, m, i, a, b, t;
vi p, sum, v;
bool ans;

void initSet(int n)
{
    for(i=1;i<=n;++i)
        p[i]=i, v[i]=1;
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
        sum[findSet(j)]+=sum[findSet(i)];
        v[findSet(i)]=0;
        p[findSet(i)]=p[findSet(j)];
    }
}
int main()
{
    p.clear(), sum.clear(), v.clear();
    p.assign(111111, 0), sum.assign(111111, 0), v.assign(111111, 0);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=1;i<=n;++i)
            scanf("%d", &a), sum[i]=a;
        initSet(n+1);
        ans=true;
        while(m--)
        {
            scanf("%d %d", &a, &b);
            Union(a+1, b+1);
        }
        for(i=1;i<=n;++i)
            if(v[i] && sum[i])
                ans=false;
        if(ans)
            puts("POSSIBLE");
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
