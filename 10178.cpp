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

int n, e, ans, visit[1111], ed, vr, i, num;
char a, b;
map<char, int> mp;
vector<vector<ii> > adj;

void dfs(int u)
{
    visit[u]=1;
    ++vr;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii v=adj[u][j];
        ++ed;
        if(!visit[v.first])
            dfs(v.first);
    }
}

int main()
{
    adj.clear(), mp.clear();
    adj.assign(1111, vector<ii>());
    while(scanf("%d %d\n", &n, &e)!=EOF)
    {
        mp.clear();
        for(i=1;i<=n;++i)
            adj[i].clear();
        num=1;
        while(e--)
        {
            a=getchar();
            getchar();
            b=getchar();
            getchar();
            if(mp.count(a)==0)
                mp[a]=num++;
            if(mp.count(b)==0)
                mp[b]=num++;
            adj[mp[a]].push_back(ii(mp[b], 1));
            adj[mp[b]].push_back(ii(mp[a], 1));
        }
        memset(visit, 0, sizeof visit);
        ans=0;
        ed=vr=0;
        for(i=1;i<=n;++i)
            if(!visit[i])
                dfs(i), ans+=ed/2-vr+1, ed=vr=0;
        printf("%d\n", ans+1);
    }
    return 0;
}
