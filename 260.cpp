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
int dx[]={1, 1, 0, 0, -1, -1};
int dy[]={0, 1, -1, 1, 0, -1};
int n, mnw, mnb, i, j, cs=1, flag, ans;
char a[222][222];
void floodfill(int r, int c, char c1, char c2,int sum)
{
    if(r<1 || r>n || c<1 || c>n)
        return;
    if(a[r][c]!=c1)
        return;
    a[r][c]=c2;
    if(c1=='w' && c==n)
    {
        flag=1;
        ans=min(ans, sum);
        return;
    }
    else
    if(c1=='b' && r==n)
    {
        flag=1;
        ans=min(ans, sum);
        return;
    }
    for(int x=0;x<6;++x)
        floodfill(r+dy[x], c+dx[x], c1, c2, sum+1);
}
int main()
{
    while(1)
    {
        scanf("%d", &n);
        getchar();
        if(!n)
            break;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cin>>a[i][j];
        }
        mnw=mnb=INF;
        for(i=1;i<=n;++i)
        {
            flag=0;
            if(a[i][1]=='w')
            {
                ans=INF;
                floodfill(i, 1, 'w', '.', 1);
                if(flag)
                    mnw=min(mnw, ans);
                floodfill(i, 1, '.', 'w', 1);
            }
        }
        for(i=1;i<=n;++i)
        {
            flag=0;
            if(a[1][i]=='b')
            {
                ans=INF;
                floodfill(1, i, 'b', '.', 1);
                if(flag)
                    mnb=min(mnb, ans);
                floodfill(1, i, '.', 'b', 1);
            }
        }
        if(mnw<mnb)
            printf("%d W\n", cs++);
        else
            printf("%d B\n", cs++);
    }
    return 0;
}
