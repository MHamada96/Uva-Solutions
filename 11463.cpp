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

int n, r, s, d, t, i, j, k, u, v, cs=1, ans;
int adj[111][111];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=-INF;
        scanf("%d", &n);
        scanf("%d", &r);
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                adj[i][j]=(i==j)?0:INF;
        while(r--)
        {
            scanf("%d %d", &u, &v);
            adj[u][v]=adj[v][u]=1;
        }
        for(k=0;k<n;++k)
            for(i=0;i<n;++i)
                for(j=0;j<n;++j)
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
        scanf("%d %d", &s, &d);
        for(i=0;i<n;++i)
            ans=max(ans, adj[s][i]+adj[i][d]);
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
