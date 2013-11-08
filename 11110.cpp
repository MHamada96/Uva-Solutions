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
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int a[111][111];
char s[1111], *p;
int i, j, n, x, num, flag;
map<int, int> mp;
void floodfill(int r, int c, int c1, int c2)
{
    if(r<1 || r>n || c<1 || c>n)
        return;
    if(a[r][c]!=c1)
        return;
    a[r][c]=c2;
    for(int q=0;q<4;q++)
        floodfill(r+dy[q], c+dx[q], c1, c2);
}
int main()
{
    while(1)
    {
        mp.clear();
        scanf("%d", &n);
        getchar();
        if(!n)
            break;
        memset(a, 0, sizeof a);
        x=n-1, num=1, flag=0;
        while(x--)
        {
            gets(s);
            for(p=strtok(s, " ");p;p=strtok(NULL, " "))
            {
                if(flag)
                {
                    flag=0;
                    j=atoi(p);
                    a[i][j]=num;
                }
                else
                {
                    flag=1;
                    i=atoi(p);
                }
            }
            num++;
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                if(a[i][j]==0)
                    a[i][j]=num;
        }
        flag=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i][j]!=0 && mp.count(a[i][j])==0)
                {
                    mp[a[i][j]]=1;
                    floodfill(i, j, a[i][j], 0);
                }
            }
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i][j]!=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("wrong\n");
        else
            printf("good\n");
    }
    return 0;
}
