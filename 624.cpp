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

int n, t, sum, i, mx, j, c;
int ans[33], vis[33], v[33];

void solve(int i, int tot, int tak)
{
    if(tot>=mx && tot<=n)
    {
        if(tak>c && tot==mx)
        {
            c=tak;
            for(j=1;j<=t;++j)
                ans[j]=vis[j];
        }
        else
        if(tot>mx)
        {
            c=tak;
            for(j=1;j<=t;++j)
                ans[j]=vis[j];
        }
        mx=tot;
    }
    if(i>t)
        return;
    if(tot>n)
        return;
    solve(i+1, tot, tak);
    vis[i]=1;
    solve(i+1, tot+v[i], tak+1);
    vis[i]=0;
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        scanf("%d", &t);
        for(i=1;i<=t;++i)
            scanf("%d", &v[i]);
        mx=-INF, c=-INF;
        memset(vis, 0, sizeof vis);
        solve(1, 0, 0);
        sum=0;
        for(i=1;i<=t;++i)
            if(ans[i])
                printf("%d ", v[i]), sum+=v[i];
        printf("sum:%d\n", sum);
    }
    return 0;
}
