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

const int N = 5555;
int n, pr[N][14], le[N], x, y, q, T, i, pv[N], fin[N], fout[N], z, len, j;
vector<int> g[N];
bool vis[N];

void dfs(int u){
    vis[u]=true;
    fin[u]=++T;
    for(int j=0;j<(int)g[u].size();++j){
        int v=g[u][j];
        if(!vis[v]){
            le[v]=le[u]+1;
            pv[v]=u;
            dfs(v);
        }
    }
    fout[u]=++T;
}

bool anc(int x, int y){
    return (fin[x]<=fin[y] && fout[y]<=fout[x]);
}

int lca(int x, int y){
    if(anc(x, y))
        return x;
    for(j=13;j>=0;--j)
        if(!anc(pr[x][j], y))
            x=pr[x][j];
    return pv[x];
}

int main(){
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        for(i=1;i<=n;++i)
            g[i].clear(), vis[i]=false;
        for(i=1;i<=n-1;++i){
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        pv[1]=1, le[1]=0, T=0;
        dfs(1);
        for(i=1;i<=n;++i)
            pr[i][0]=pv[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=13;++j)
                pr[i][j]=pr[pr[i][j-1]][j-1];
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &x, &y);
            if(le[x]>le[y])
                swap(x, y);
            z=lca(x, y);
            len=le[x]+le[y]-2*le[z];
            if(len%2==0){
                for(i=1;i<=len/2;++i)
                    y=pv[y];
                printf("The fleas meet at %d.\n", y);
            }
            else{
                if(le[y]==le[x]){
                    for(i=1;i<=len/2;++i)
                        x=pv[x], y=pv[y];
                    if(x>y)
                        swap(x, y);
                    printf("The fleas jump forever between %d and %d.\n", x, y);
                }
                else{
                    for(i=1;i<=len/2;++i)
                        y=pv[y];
                    x=pv[y];
                    if(x>y)
                        swap(x, y);
                    printf("The fleas jump forever between %d and %d.\n", x, y);
                }
            }
        }
    }
    return 0;
}
