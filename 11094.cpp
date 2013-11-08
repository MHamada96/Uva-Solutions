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
int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};
int m, n, x, y, i, j, ans;
char a[22][22], ch;
int floodfill(int r, int c, char c1, char c2)
{
    if(r>m || r<1)
        return 0;
    if(c<1)
        c=n;
    if(c>n)
        c=1;
    if(a[r][c]!=c1)
        return 0;
    a[r][c]=c2;
    int sum=1;
    for(int p=0;p<4;++p)
        sum+=floodfill(r+dy[p], c+dx[p], c1, c2);
    return sum;
}
int main()
{
    while(scanf("%d %d", &m, &n)!=EOF)
    {
        getchar();
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
                cin>>a[i][j];
        }
        scanf("%d %d", &x, &y);
        ++x, ++y;
        ch=a[x][y];
        ans=0;
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
                if(a[i][j]==ch)
                    a[i][j]='l';
                else
                    a[i][j]='w';
        }
        floodfill(x, y, 'l', '.');
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i][j]=='l')
                    ans=max(ans, floodfill(i, j, 'l', '.'));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
