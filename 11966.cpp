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

int t, n, ans, i, j, cs=1;
double x, y, d, tmp;
vi p;
vector<dd> v;

double dist(dd a, dd b)
{
    return hypot(a.first-b.first, a.second-b.second);
}
void rounding(double &v)
{
    v*=100000.0;
    v+=0.5;
    ll tmp=(ll)floor(v);
    v=tmp/100000.0;
}
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
        ans--;
    }
}

int main()
{
    p.clear();
    p.assign(1010, 0);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lf", &n, &d);
        initSet(n);
        v.clear();
        while(n--)
        {
            scanf("%lf %lf", &x, &y);
            v.push_back(dd(x, y));
        }
        rounding(d);
        for(i=0;i<(int)v.size();++i)
            for(j=0;j<(int)v.size();++j)
            {
                tmp=dist(v[i], v[j]);
                rounding(tmp);
                if(i!=j && tmp<=d)
                    Union(i+1, j+1);
            }
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
