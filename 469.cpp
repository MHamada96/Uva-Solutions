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
int n, i, t, j, flag, m, x, y;
char a[111][111], ch, s[111];
int floodfill(int r, int c, char c1, char c2)
{
    if(r<0 || r>n || c<0 || c>m)
        return 0;
    if(a[r][c]!=c1)
        return 0;
    a[r][c]=c2;
    int ans=1;
    for(int p=0;p<8;++p)
        ans+=floodfill(r+dy[p], c+dx[p], c1, c2);
    return ans;
}
int main()
{
    scanf("%d", &t);
    gets(s);
    gets(s);
    while(t--)
    {
        i=0;
        while(1)
        {
            gets(s);
            if(s[0]!='L' && s[0]!='W')
                break;
            strcpy(a[i], s);
            ++i;
        }
        n=i-1, m=(int)strlen(a[0])-1;
        sscanf(s, "%d %d", &x, &y);
        if(flag)
            putchar('\n');
        flag=1;
        while(1)
        {
            printf("%d\n", floodfill(x-1, y-1, 'W', '.'));
            floodfill(x-1, y-1, '.', 'W');
            gets(s);
            if(strcmp(s, "")==0||feof(stdin))
                break;
            sscanf(s, "%d %d", &x, &y);
        }
    }
    return 0;
}
