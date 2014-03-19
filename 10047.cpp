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
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

struct Node
{
    int x, y, d, c, t;
    Node(int xx, int yy, int dd, int cc, int tt)
    {
        x=xx, y=yy, d=dd, c=cc, t=tt;
    }
};
int m, n, i, j, ans, r, c, dir, col, tim, cs=1;
char s[33][33];
queue<Node> q;
bool blank=false;
int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};
int v[33][33][4][5];

int main()
{
    while(1)
    {
        q=queue<Node>();
        memset(v, 0, sizeof v);
        scanf("%d %d", &m, &n);
        if(!m && !n)
            break;
        getchar();
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                s[i][j]=getchar();
                if(s[i][j]=='S')
                    q.push(Node(i, j, 0, 0, 0));
            }
            getchar();
        }
        ans=0;
        if(blank)
            putchar('\n');
        blank=true;
        while(!q.empty())
        {
            Node temp=q.front();q.pop();
            r=temp.x, c=temp.y, dir=temp.d, col=temp.c, tim=temp.t;
            if(v[r][c][dir][col])
                continue;
            if(s[r][c]=='#')
                continue;
            if(s[r][c]=='T' && col==0)
            {
                ans=tim;
                break;
            }
            v[r][c][dir][col]=1;
            if(!(r+dy[dir]<1 || r+dy[dir]>m || c+dx[dir]<1 || c+dx[dir]>n))
                q.push(Node(r+dy[dir], c+dx[dir], dir, (col+1)%5, tim+1));
            q.push(Node(r, c, (dir+1)%4, col, tim+1));
            q.push(Node(r, c, (dir+3)%4, col, tim+1));
        }
        printf("Case #%d\n", cs++);
        if(ans)
            printf("minimum time = %d sec\n", ans);
        else
            printf("destination not reachable\n");
    }
    return 0;
}
