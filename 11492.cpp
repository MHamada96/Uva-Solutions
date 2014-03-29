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

int m, i, j, num, u, v, w, x, y, d, p, ans;
int dist[8010][33];
char s[55], e[55], a[55], b[55], r[55];
vector<vector<pair<int, ii> > > adj;
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
map<string, int> mp;

int main()
{
    adj.clear();
    adj.assign(4010, vector<pair<int, ii> >());
    while(1)
    {
        scanf("%d", &m);
        num=1;
        mp.clear();
        for(i=1;i<=2*m;++i)
            adj[i].clear();
        for(i=1;i<=2*m;++i)
            for(j=1;j<=26;++j)
                dist[i][j]=INF;
        if(!m)
            break;
        scanf("%s %s", s, e);
        if(mp.count(s)==0)
            mp[s]=num++;
        if(mp.count(e)==0)
            mp[e]=num++;
        while(m--)
        {
            scanf("%s %s %s", a, b, r);
            if(mp.count(a)==0)
                mp[a]=num++, x=num-1;
            else
                x=mp[a];
            if(mp.count(b)==0)
                mp[b]=num++, y=num-1;
            else
                y=mp[b];
            w=(int)strlen(r);
            adj[x].push_back(make_pair(y, ii(w, (int)r[0]-96)));
            adj[y].push_back(make_pair(x, ii(w, (int)r[0]-96)));
        }
        pq.push(make_pair(0, ii(mp[s], 0)));
        dist[mp[s]][0]=0;
        while(!pq.empty())
        {
            pair<int, ii> temp=pq.top();
            pq.pop();
            d=temp.first;
            u=temp.second.first;
            p=temp.second.second;
            for(j=0;j<(int)adj[u].size();++j)
            {                    
                pair<int, ii> v=adj[u][j];
                if(dist[u][p]+v.second.first<dist[v.first][v.second.second] && v.second.second!=p)
                {
                    dist[v.first][v.second.second]=dist[u][p]+v.second.first;
                    pq.push(make_pair(dist[v.first][v.second.second], ii(v.first, v.second.second)));
                }
            }
        }
        ans=INF;
        if(mp[e]==mp[s])
            ans=0;
        for(i=1;i<=26;++i)
            ans=min(ans, dist[mp[e]][i]);
        if(ans==INF)
            puts("impossivel");
        else
            printf("%d\n", ans);
    }
    return 0;
}
