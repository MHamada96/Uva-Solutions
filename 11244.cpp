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
int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[]={0, 1, 1, 1, 0, -1, -1, -1};
int r, c, ans, i, j, flag;
char a[111][111];
int main()
{
    while(1)
    {
        scanf("%d %d", &r, &c);
        getchar();
        if(!r && !c)
            break;
        for(i=1;i<=r;++i)
        {
            for(j=1;j<=c;++j)
                cin>>a[i][j];
        }
        ans=0;
        for(i=1;i<=r;++i)
        {
            for(j=1;j<=c;++j)
            {
                if(a[i][j]=='*')
                {
                    flag=0;
                    for(int x=0;x<8;++x)
                        if(i+dy[x]>0 && i+dy[x]<=r && j+dx[x]>0 && j+dx[x]<=c)
                            if(a[i+dy[x]][j+dx[x]]=='*')
                                flag=1;
                    if(!flag)
                        ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
