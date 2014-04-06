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

int i, c, n, d[10], x, j;
ll tmp, fact[15], tot[20];

int main()
{
    fact[0]=fact[1]=1;
    for(i=2;i<=12;++i)
        fact[i]=fact[i-1]*(ll)i;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        memset(d, 0, sizeof d);
        for(i=1;i<=n;++i)
            scanf("%d", &x), d[x]++;
        memset(tot, 0, sizeof tot);
        for(i=0;i<10;++i)
        {
            tmp=fact[n-1];
            if(d[i])
            {
                for(j=0;j<10;++j)
                    if(i!=j && d[j])
                        tmp/=(fact[d[j]]);
                tmp/=fact[d[i]-1];
                tmp*=(ll)i;
                for(j=1;j<=n;++j)
                    tot[j]+=tmp;
            }
        }
        c=0;
        for(i=n;i>=0;--i)
        {
            tot[i]+=c;
            c=tot[i]/10;
            if(i!=0)
                tot[i]%=10;
        }
        for(i=0;i<=n;++i)
            if(tot[i]!=0)
                break;
        if(i==n+1)
            i=n;
        for(;i<=n;++i)
                printf("%lld", tot[i]);
        putchar('\n');
    }
    return 0;
}
