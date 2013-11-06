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
char a[66][66], in, dir;
int t, n, m, i, j, flag=0;
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
        if(a[i][j]=='*')
            i+=1;
    }
    if(dir=='E')
     {
        j+=1;
        if(a[i][j]=='*')
            j-=1;
    }
    if(dir=='S')
     {
        i+=1;
        if(a[i][j]=='*')
            i-=1;
    }
    if(dir=='W')
     {   
        j-=1;
        if(a[i][j]=='*')
            j+=1;
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        getchar();
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                a[i][j]=getchar();
            getchar();
        }
        scanf("%d %d", &i, &j);
        getchar();
        dir='N';
        while(1)
        {
            in=getchar();
            if(in=='Q')
                break;
            if(in=='R')
                dir=getdirr();
            else
            if(in=='L')
                dir=getdirl();
            else
            if(in=='F')
                inc();
        }
        getchar();
        if(flag)
            putchar('\n');
        flag=1;
        printf("%d %d %c\n", i, j, dir);
    }
    return 0;
}
