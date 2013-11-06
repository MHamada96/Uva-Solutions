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
char a[111][111], in, dir, visit[111][111];
int n, m, i, j, x, y, foo, ans;
char getdirr()
{
    if(dir=='N')
        return 'E';
    if(dir=='E')
        return 'S';
    if(dir=='S')
        return 'W';
    if(dir=='W')
        return 'N';
}
char getdirl()
{
    if(dir=='N')
        return 'W';
    if(dir=='W')
        return 'S';
    if(dir=='S')
        return 'E';
    if(dir=='E')
        return 'N';
}
void inc()
{
    if(dir=='N')
    {
        i-=1;
        if(a[i][j]=='#'||i<1||i>n )
            i+=1;
    }
    if(dir=='E')
    {
        j+=1;
        if(a[i][j]=='#'||j<1 ||j>m)
            j-=1;
    }
    if(dir=='S')
    {
        i+=1;
        if(a[i][j]=='#'||i<1||i>n)
            i-=1;
    }
    if(dir=='W')
    {   
        j-=1;
        if(a[i][j]=='#'||j<1||j>m)
            j+=1;
    }
    if(a[i][j]=='*' && !visit[i][j])
        ans++, visit[i][j]=1;
}
int main()
{
    while(1)
    {
        scanf("%d %d %d", &n, &m, &foo);
        getchar();
        if(!n && !m && !foo)
            break;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j){
                a[i][j]=getchar();
            if(a[i][j]=='O')
                dir='W', x=i, y=j;
            if(a[i][j]=='L')
                dir='E', x=i, y=j;
            if(a[i][j]=='N')
                dir='N', x=i, y=j;
            if(a[i][j]=='S')
                dir='S', x=i, y=j;}
            getchar();
        }
        ans=0;
        i=x, j=y;
        memset(visit, 0, sizeof visit);
        while(1)
        {
            in=getchar();
            if(in=='\n')
                break;
            if(in=='D')
                dir=getdirr();
            else
            if(in=='E')
                dir=getdirl();
            else
            if(in=='F')
                inc();
        }
        printf("%d\n", ans);
    }
    return 0;
}
