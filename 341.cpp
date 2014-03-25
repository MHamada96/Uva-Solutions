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

int n, t, x, d, i, j, cs=1, s, e, u;
ii temp, v;
vector<vector<ii> >adj;
vi dist, parent;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void print_path(int u)
{
    if(parent[u]==u)
    {
        printf(" %d", u);
        return;
    }
    print_path(parent[u]);
    printf(" %d", u);
}
int main()
{
    adj.assign(15, vector<ii>());
    dist.assign(15, INF);
    parent.assign(15, 0);
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        for(i=1;i<=n;++i)
            adj[i].clear(), dist[i]=INF;
        for(i=1;i<=n;++i)
        {
            scanf("%d", &t);
            while(t--)
            {
                scanf("%d %d", &x, &d);
                adj[i].push_back(ii(x, d));
            }
        }
        scanf("%d %d", &s, &e);
        pq.push(ii(0, s));
        dist[s]=0;
        parent[s]=s;
        while(!pq.empty())
        {
            temp=pq.top(), pq.pop();
            d=temp.first, u=temp.second;
            if(d==dist[u])
                for(j=0;j<(int)adj[u].size();++j)
                {
                    v=adj[u][j];
                    if(dist[u]+v.second<dist[v.first])
                    {
                        dist[v.first]=dist[u]+v.second;
                        parent[v.first]=u;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
        }
        printf("Case %d: Path =", cs++);
        print_path(e);
        printf("; %d second delay\n", dist[e]);
    }
    return 0;
}
