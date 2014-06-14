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

char s[100];
int i, j, flag, x, y, c, mx, src;
vector<vector<ii> > adj;
vi dist, vis;

void dfs(int u){
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii v=adj[u][j];
        if(!vis[v.first])
            dist[v.first]=dist[u]+v.second;
        if(!vis[v.first])
            dfs(v.first);
    }
}

int main(){
    adj.clear(), adj.assign(100100, vector<ii>());
    dist.clear(), dist.assign(100100, 0);
    vis.clear(), vis.assign(100100, 0);
    while(1){
        flag=0;
        for(i=1;i<=100000;++i)
            adj[i].clear(), dist[i]=0, vis[i]=0;
        while(gets(s)!=NULL){
            if(strlen(s)==0){
                flag=1;
                break;
            }
            sscanf(s, "%d %d %d", &x, &y, &c);
            adj[x].push_back(ii(y, c));
            adj[y].push_back(ii(x, c));
        }
        dfs(1);
        mx=-INF;
        for(i=1;i<=100000;++i){
            vis[i]=0;
            if(dist[i]>mx)
                src=i, mx=dist[i];
            dist[i]=0;
        }
        dfs(src);
        mx=-INF;
        for(i=1;i<=100000;++i)
            mx=max(dist[i], mx);
        printf("%d\n", mx);
        if(!flag)
            break;
    }
    return 0;
}
