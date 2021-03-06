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
int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
int dy[]={1, 1, 0, -1, -1, -1, 0, 1};
int n, ans, i, j, cs=1, m;
char a[111][111];
void floodfill(int r, int c, char c1, char c2)
{
    if(r<1 || r>m || c<1 || c>n)
        return;
    if(a[r][c]!=c1)
        return;
    a[r][c]='.';
    for(int x=0;x<8;++x)
        floodfill(r+dy[x], c+dx[x], c1, c2);
}
int main()
{
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(!n && !m)
            break;
        ans=0;
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
                cin>>a[i][j];
        }
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i][j]=='@')
                {
                    ans++;
                    floodfill(i, j, '@', '.');
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
