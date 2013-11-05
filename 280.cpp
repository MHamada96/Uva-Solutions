#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <new>
#include <fstream>
#include <map>
#include <bitset>
#include <cstring>
 using namespace std;
#define ll long long int 
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
int a[111][111], visit[111];
int n, v, u, q, ans;
vi node;
void dfs(int v)
{
    for(int i=1;i<=n;++i)
    {
        if(a[v][i] && !visit[i])
            visit[i]=1, dfs(i);
    }
}
int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        memset(a, 0, sizeof a);
        memset(visit, 0, sizeof visit);
        while(1)
        {
            scanf("%d", &u);
            if(!u)
                break;
            while(1)
            {
                scanf("%d", &v);
                if(!v)
                    break;
                a[u][v]=1;
            }
        }
        scanf("%d", &q);
        while(q--)
        {
            ans=0;
            node.clear();
            memset(visit, 0, sizeof visit);
            scanf("%d", &v);
            dfs(v);
            for(int i=1;i<=n;++i)
            {
                if(!visit[i])
                {
                    ans++;
                    node.push_back(i);
                } 
            }
            printf("%d", ans);
            for(int i=0;i<node.size();++i)
                printf(" %d", node[i]);
            putchar('\n');
        }
    }
    return 0;
}
