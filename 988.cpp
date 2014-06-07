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

int n, i, j, c, ans;
vi path, topo, vis, death;
vector<vector<ii> > adj;
bool blank=false;

void dfs(int u)
{
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        if(!vis[adj[u][j].first])
            dfs(adj[u][j].first);
    }
    topo.push_back(u);
}

int main()
{
    path.clear(), topo.clear(), adj.clear(), vis.clear();
    adj.assign(111111, vector<ii>()), path.assign(111111, 0), vis.assign(111111, 0);
    while(scanf("%d", &n)!=EOF)
    {
        for(i=1;i<111111;++i)
            adj[i].clear();
        death.clear();
        for(i=1;i<=n;++i)
        {
            scanf("%d", &c);
            if(!c)
                death.push_back(i);
            while(c--)
            {
                scanf("%d", &j);
                adj[i].push_back(ii(j+1, 1));
            }
        }
        for(i=1;i<100000;++i)
            path[i]=0, vis[i]=0;
        topo.clear();
        for(i=1;i<=n;++i)
            if(!vis[i])
                dfs(i);
        reverse(topo.begin(), topo.end());
        path[1]=1;
        for(i=0;i<(int)topo.size();++i)
        {
            int u=topo[i];
            for(j=0;j<(int)adj[u].size();++j)
            {
                ii v=adj[u][j];
                path[v.first]+=path[u];
            }
        }
        if(blank)
            putchar('\n');
        blank=true;
        ans=0;
        for(i=0;i<(int)death.size();++i)
            ans+=path[death[i]];
        printf("%d\n", ans);
    }
    return 0;
}
