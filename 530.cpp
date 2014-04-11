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

ll n, m, a, b, i, j, g;

int main()
{
    while(1)
    {
        scanf("%lld %lld", &n, &m);
        if(!n && !m)
            break;
        i=max(n-m, m);
        ++i;
        m=min(n-m, m);
        j=1;
        a=b=1;
        while(1)
        {
            if(i<=n)
                a*=i, ++i;
            if(j<=m)
                b*=j, ++j;
            g=gcd(a, b);
            a/=g, b/=g;
            if(i>n && j>m)
                break;
        }
        printf("%lld\n", a/b);
    }
    return 0;
}
