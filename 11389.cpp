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

int n, d, r, ans, i;
int m[111], e[111];

int main()
{
    while(1)
    {
        scanf("%d %d %d", &n, &d, &r);
        if(!n && !d && !r)
            break;
        for(i=1;i<=n;++i)
            scanf("%d", &m[i]);
        for(i=1;i<=n;++i)
            scanf("%d", &e[i]);
        sort(m+1, m+n+1);
        sort(e+1, e+n+1);
        ans=0;
        for(i=1;i<=n;++i)
            ans+=((m[i]+e[n-i+1])<=d)?0:(r*(m[i]+e[n-i+1]-d));
        printf("%d\n", ans);
    }
    return 0;
}
