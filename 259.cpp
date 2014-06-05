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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int mf, f, ss=0, t=37, res[55][55], i, j, n, flag, x;
vector<vector<ii> > adj;
queue<int> q;
vi p;
char ch, s[111], a, b;
map<char, int> mp;
bitset<55> bs;

void augment(int v, int minCost)
{
    if(v==ss)
    {
        f=minCost;
        return;
    }
    else
    if(p[v]!=-1)
    {
        augment(p[v], min(minCost, res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
}

int main()
{
    adj.clear(), adj.assign(40, vector<ii>());
    p.clear(), p.assign(40, -1);
    for(i=1;i<=26;++i)
        mp[(char)(i+64)]=i;
    while(1)
    {
        n=0;
        flag=0;
        memset(res, 0, sizeof res);
        for(i=0;i<=39;++i)
            adj[i].clear(), p[i]=-1;
        for(i=27;i<=36;++i)
            res[i][t]=1, adj[i].push_back(ii(t, 1));
        while(gets(s)!=NULL)
        {
            if(strlen(s)==0 || strcmp(s, "")==0)
            {
                flag=1;
                break;
            }
            a=s[0];
            b=s[1];
            i=(int)b-48;
            n+=i;
            res[ss][mp[a]]+=i;
            adj[ss].push_back(ii(mp[a], i));
            j=mp[a];
            for(i=3;;++i)
            {
                if(s[i]==';')
                    break;
                x=(int)s[i]-48+27;
                res[j][x]=1;
                adj[j].push_back(ii(x, 1));
            }
        }
        mf=0;
        while(1)
        {
            q=queue<int>();
            q.push(ss);
            bs.reset();
            for(i=0;i<38;++i)
                p[i]=-1;
            bs[ss]=1;
            f=0;
            while(!q.empty())
            {
                int u=q.front();q.pop();
                if(u==t)
                    break;
                for(j=0;j<38;++j)
                {
                    if(res[u][j]>0 && !bs[j])
                    {
                        bs[j]=1;
                        p[j]=u;
                        q.push(j);
                    }
                }
            }
            augment(t, INF);
            if(f==0)
                break;
            mf+=f;
        }
        if(mf!=n)
            puts("!");
        else
        {
            for(i=27;i<37;++i)
            {
                for(j=1;j<=26;++j)
                {
                    if(res[i][j]==1)
                    {
                        putchar(j+64);
                        break;
                    }
                }
                if(j==27)
                    putchar('_');
            }
            putchar('\n');
        }
        if(!flag)
            break;
    }
    return 0;
}
