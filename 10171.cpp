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

int n, c, i, j, k, a, b, ans;
int y[55][55], m[55][55];
char u, v, t, d, st, en;
map<char, int> yy, mm;
map<int, char> ry, rm;
vector<char> vc;

int main()
{
    while(1)
    {
        a=b=1;
        scanf("%d", &n);
        getchar();
        if(!n)
            break;
        yy.clear(), mm.clear(), ry.clear(), rm.clear();
        for(i=1;i<=52;++i)
            for(j=1;j<=52;++j)
                y[i][j]=m[i][j]=((i==j)?0:INF);
        while(n--)
        {
            scanf("%c %c %c %c %d", &t, &d, &u, &v, &c);
            getchar();
            if(t=='Y')
            {
                if(yy.count(u)==0)
                    yy[u]=a++, ry[a-1]=u;
                if(yy.count(v)==0)
                    yy[v]=a++, ry[a-1]=v;
                y[yy[u]][yy[v]]=min(c, y[yy[u]][yy[v]]);
                if(d=='B')
                    y[yy[v]][yy[u]]=min(c, y[yy[v]][yy[u]]);
            }
            if(t=='M')
            {
                if(mm.count(u)==0)
                    mm[u]=b++, rm[b-1]=u;
                if(mm.count(v)==0)
                    mm[v]=b++, rm[b-1]=v;
                m[mm[u]][mm[v]]=min(c, m[mm[u]][mm[v]]);
                if(d=='B')
                    m[mm[v]][mm[u]]=min(c, m[mm[v]][mm[u]]);
            }
        }
        vc.clear();
        ans=INF;
        for(k=1;k<a;++k)
            for(i=1;i<a;++i)
                for(j=1;j<a;++j)
                    y[i][j]=min(y[i][j], y[i][k]+y[k][j]);
        for(k=1;k<b;++k)
            for(i=1;i<b;++i)
                for(j=1;j<b;++j)
                    m[i][j]=min(m[i][j], m[i][k]+m[k][j]);
        scanf("%c %c", &st, &en);
        getchar();
        if(yy.count(st)==0)
            yy[st]=a++, ry[a-1]=st;
        if(mm.count(en)==0)
            mm[en]=b++, rm[b-1]=en;
        for(i=1;i<a;++i)
        {
            if(mm.count(ry[i])!=0)
            {
                if(y[yy[st]][i]+m[mm[en]][mm[ry[i]]]<ans)
                {
                    ans=y[yy[st]][i]+m[mm[en]][mm[ry[i]]];
                    vc.clear();
                    vc.push_back(ry[i]);
                }
                else
                if(y[yy[st]][i]+m[mm[en]][mm[ry[i]]]==ans)
                    vc.push_back(ry[i]);
            }
        }
        if(ans==INF)
        {
            if(st==en)
                ans=0, vc.clear(), vc.push_back(st);
        }
        if(ans!=INF)
        {
            printf("%d", ans);
            sort(vc.begin(), vc.end());
            for(i=0;i<(int)vc.size();++i)
                printf(" %c", vc[i]);
            putchar('\n');
        }
        else
            printf("You will never meet.\n");
    }
    return 0;
}
