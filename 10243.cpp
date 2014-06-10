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

int n, i, x, c, dp[1111][5], root, mx;
vector<vector<ii> > adj;
vi p;

int MVC(int u, int flag)
{
    if(dp[u][flag]!=-1)
        return dp[u][flag];
    int ans=0;
    if(adj[u].size()==1 && u!=root)
        ans=flag;
    else
    if(!flag)
    {
        ans=0;
        for(int j=0;j<(int)adj[u].size();++j)
            if(p[u]!=adj[u][j].first)
            {
                p[adj[u][j].first]=u;
                ans+=MVC(adj[u][j].first, 1);
            }
    }
    else
    if(flag)
    {
        ans=1;
        for(int j=0;j<(int)adj[u].size();++j)
            if(p[u]!=adj[u][j].first)
            {
                p[adj[u][j].first]=u;
                ans+=min(MVC(adj[u][j].first, 0), MVC(adj[u][j].first, 1));
            }
    }
    return dp[u][flag]=ans;
}

int main()
{
    adj.clear(), p.clear();
    adj.assign(1111, vector<ii>()), p.assign(1111, 0);
    while(1)
    {
        scanf("%d", &n);
        mx=-INF;
        if(!n)
            break;
        for(i=1;i<=n;++i)
            adj[i].clear();
        root=1, mx=1;
        for(i=1;i<=n;++i)
        {
            p[i]=-1;
            scanf("%d", &c);
            if(c>mx)
                mx=c, root=i;
            while(c--)
                scanf("%d", &x), adj[i].push_back(ii(x, 1));
        }
        memset(dp, -1, sizeof dp);
        if(n==1)
            printf("1\n");
        else
            printf("%d\n", min(MVC(root, 0), MVC(root, 1)));
    }
    return 0;
}
