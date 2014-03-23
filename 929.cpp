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

int n, m, t, i, pos, j;
int a[1010][1010];
vi dist;
vector<vector<ii> > adj;
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                scanf("%d", &a[i][j]);
        adj.clear();
        adj.assign(n*m+2, vector<ii>());
        for(i=1;i<=n*m;++i)
            adj[i].clear();
        dist.clear();
        dist.assign(n*m+2, INF);
        pos=1;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                if(i-1>0)
                    adj[pos].push_back(ii(pos-m, a[i-1][j]));
                if(i+1<=n)
                    adj[pos].push_back(ii(pos+m, a[i+1][j]));
                if(j-1>0)
                    adj[pos].push_back(ii(pos-1, a[i][j-1]));
                if(j+1<=m)
                    adj[pos].push_back(ii(pos+1, a[i][j+1]));
                ++pos;
            }
        pq.push(ii(0, 1));
        dist[1]=0;
        while(!pq.empty())
        {
            ii temp=pq.top();pq.pop();
            int d=temp.first, u=temp.second;
            if(d==dist[u])
                for(j=0;j<(int)adj[u].size();++j)
                {
                    ii v=adj[u][j];
                    if(dist[u]+v.second<dist[v.first])
                    {
                        dist[v.first]=dist[u]+v.second;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
        }
        printf("%d\n", dist[n*m]+a[1][1]);
    }
    return 0;
}
