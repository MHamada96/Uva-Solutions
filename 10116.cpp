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
char a[15][15], visit[15][15][1];
int n, m, s, ans, flag, i, j;
void dfs()
{
    if(i<1 || i>n || j<1 || j>m)
        return;
    if(visit[i][j][1])
    {
        flag=1;
        return;
    }
    ans++;
    visit[i][j][1]=ans;
    if(a[i][j]=='N')
        i-=1, dfs();
    else
    if(a[i][j]=='W')
        j-=1, dfs();
    else
    if(a[i][j]=='S')
        i+=1, dfs();
    else
    if(a[i][j]=='E')
        j+=1, dfs();
}
int main()
{
    while(1)
    {
        scanf("%d %d %d", &n, &m, &s);
        if(!n && !m && !s)
            break;
        getchar();
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                a[i][j]=getchar();
            getchar();
        }
        memset(visit, 0, sizeof visit);
        i=1, j=s;
        flag=ans=0;
        dfs();
        if(flag)
            printf("%d step(s) before a loop of %d step(s)\n", visit[i][j][1]-1, ans-visit[i][j][1]+1);
        else
            printf("%d step(s) to exit\n", ans);
    }
    return 0;
}
