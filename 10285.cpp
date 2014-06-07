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

int t, r, c, i, j, num, tmp, ans;
int a[111][111];
char s[111];
vector<vector<ii> > adj;
vi dist, vis, topo;

void dfs(int u)
{
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii v=adj[u][j];
        if(!vis[v.first])
            dfs(v.first);
    }
    topo.push_back(u);
}

int main()
{
    dist.clear(), vis.clear();
    adj.clear(), adj.assign(111111, vector<ii>());
    dist.assign(111111, 0), vis.assign(111111, 0);
    scanf("%d", &t);
    while(t--)
    {
        s[0]='\0';
        scanf("%s %d %d", s, &r, &c);
        num=1;
        topo.clear();
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
                scanf("%d", &a[i][j]);
        for(i=1;i<=100000;++i)
            adj[i].clear();
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
            {
                if(j-1>=1 && a[i][j]>a[i][j-1])
                    adj[num].push_back(ii(num-1, -1));
                if(i-1>=1 && a[i][j]>a[i-1][j])
                    adj[num].push_back(ii(num-c, -1));
                if(j+1<=c && a[i][j]>a[i][j+1])
                    adj[num].push_back(ii(num+1, -1));
                if(i+1<=r && a[i][j]>a[i+1][j])
                    adj[num].push_back(ii(num+c, -1));
                ++num;
            }
        for(i=1;i<=100000;++i)
            dist[i]=1, vis[i]=0;
        for(i=1;i<num;++i)
            if(!vis[i])
                dfs(i);
        reverse(topo.begin(), topo.end());
        ans=1;
        for(i=0;i<(int)topo.size();++i)
        {
            int u=topo[i];
            for(j=0;j<(int)adj[u].size();++j)
            {
                ii v=adj[u][j];
                dist[v.first]=max(dist[v.first], dist[u]+1);
                ans=max(ans, dist[v.first]);
            }
        }
        printf("%s: %d\n", s, ans);
    }
    return 0;
}
