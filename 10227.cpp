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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int c, ans, p, t, i, a, b, vis[111], j;
vector<set<int> > v;
bool blank=false;
char s[55];

bool same(int a, int b)
{
    set<int>::iterator x, y;
    x=v[a].begin(), y=v[b].begin();
    while(1)
    {
        if(x==v[a].end() && y==v[b].end())
            return true;
        if(x==v[a].end() || y==v[b].end())
            return false;
        if(*x!=*y)
            return false;
        ++x, ++y;
    }
}
void check()
{   
    for(i=1;i<=p;++i)
        if(!vis[i])
        {
            ++ans;
            for(j=i+1;j<=p;++j)
                if(same(i, j))
                    vis[j]=1;
        }
}

int main()
{
    scanf("%d", &c);
    v.clear();
    v.assign(111, set<int>());
    while(c--)
    {
        scanf("%d %d", &p, &t);
        getchar();
        for(i=1;i<=p;++i)
            v[i].clear();
        while(gets(s))
        {
            if(strlen(s)==0)
                break;
            sscanf(s, "%d %d", &a, &b);
            v[a].insert(b);
        }
        ans=0;
        memset(vis, 0, sizeof vis);
        check();
        if(blank)
            putchar('\n');
        blank=true;
        printf("%d\n", ans);
    }
    return 0;
}
