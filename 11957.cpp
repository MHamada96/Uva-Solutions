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

int t, n, i, j, num, cs=1, src, ans;
vector<vector<ii> > adj;
vi path, top, vis;
char s[111][111];

void dfs(int u)
{
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii v=adj[u][j];
        if(!vis[v.first])
            dfs(v.first);
    }
    top.push_back(u);
}
int main()
{
    path.clear(), top.clear(), adj.clear(), vis.clear();
    adj.assign(100000, vector<ii>()), path.assign(100000, 0), vis.assign(100000, 0);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        getchar();
        num=n+1;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                s[i][j]=getchar();
            getchar();
        }
        for(i=1;i<=10000;++i)
            adj[i].clear(), path[i]=0, vis[i]=0;
        top.clear();
        for(i=2;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                if(s[i][j]=='B')
                {
                    vis[num]=1;
                    num++;
                    continue;
                }

                if(s[i][j]=='W')
                    src=num;
                if(i-1>=1 && j-1>=1 && s[i-1][j-1]=='.')
                    adj[num].push_back(ii(num-n-1, 1));
                else
                if(i-1>=1 && j-1>=1 && s[i-1][j-1]=='B' && i-2>=1 && j-2>=1 && s[i-2][j-2]=='.')
                    adj[num].push_back(ii(num-2*n-2, 1));
                if(i-1>=1 && j+1<=n && s[i-1][j+1]=='.')
                    adj[num].push_back(ii(num-n+1, 1));
                else
                if(i-1>=1 && j+1<=n && s[i-1][j+1]=='B' && i-2>=1 && j+2<=n && s[i-2][j+2]=='.')
                    adj[num].push_back(ii(num-2*n+2, 1));
                num++;
            }
        for(i=1;i<num;++i)
            if(!vis[i])
                dfs(i);
        reverse(top.begin(), top.end());
        path[src]=1;
        for(i=0;i<(int)top.size();++i)
        {
            int u=top[i];
            for(j=0;j<(int)adj[u].size();++j)
            {
                ii v=adj[u][j];
                path[v.first]=(path[v.first]+path[u])%1000007;
            }
        }
        ans=0;
        for(i=1;i<=n;++i)
            ans+=path[i], ans%=1000007;
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
