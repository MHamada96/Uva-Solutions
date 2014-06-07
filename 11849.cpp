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

int n, m, i, j, pos=1, ans;
int a[1000010], b[1000010], c[2000100];

int main()
{
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(!n && !m)
            break;
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]);
        j=1, pos=1;
        ans=0;
        for(i=1;i<=m;++i)
        {
            scanf("%d", &b[i]);
            while(j<=n && a[j]<=b[i])
                c[pos++]=a[j++];
            c[pos++]=b[i];
        }
        for(i=2;i<pos;++i)
            if(c[i]==c[i-1])
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
