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
int n, i, j, cs=1, x, y, sum, p;
int a[11][11], visit[11][11];
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        if(!n)
            break;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                scanf("%d", &a[i][j]);
        printf("Case %d: ", cs++);
        x=1, y=1, p=0;
        int l=n/2;
        if(n%2)
            ++l;
        memset(visit, 0, sizeof visit);
        while(x<=l)
        {
            if(p)
                putchar(' ');
            p=1;
            sum=0;
            for(i=x;i<=n-x+1;++i)
            {
                if(visit[i][x]==0)
                    sum+=a[i][x], visit[i][x]=1;
                if(visit[i][n-x+1]==0)
                    sum+=a[i][n-x+1], visit[i][n-x+1]=1;
            }
            for(j=y;j<=n-y+1;++j)
            {
                if(visit[y][j]==0)
                    sum+=a[y][j], visit[y][j]=1;
                if(visit[n-y+1][j]==0)
                    sum+=a[n-y+1][j], visit[n-y+1][j]=1;
            }
            printf("%d", sum);
            ++x, ++y;
        }
        putchar('\n');
    }
    return 0;
}
