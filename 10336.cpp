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
typedef pair<char, int> ci;
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
vector<ci> v;
int h, w, t, i, j, cs=1, x, ans;
char a[1111][1111];
bool cmp(ci a, ci b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first<b.first;
}
void floodfill(int r, int c, char c1, char c2)
{
    if(r<1 || r>h || c<1 || c>w)
        return;
    if(a[r][c]!=c1)
        return;
    a[r][c]=c2;
    for(int p=0;p<4;++p)
        floodfill(r+dy[p], c+dx[p], c1, c2);
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        v.clear();
        scanf("%d %d", &h, &w);
        for(i=1;i<=h;++i)
            for(j=1;j<=w;++j)
                cin>>a[i][j];
        for(x=97;x<=122;++x)
        {
            ans=0;
            for(i=1;i<=h;++i)
            {
                for(j=1;j<=w;++j)
                {
                    if(a[i][j]==(char)x)
                    {
                        ++ans;
                        floodfill(i, j, (char)x, '.');
                    }
                }
            }
            if(ans>0)
                v.push_back(make_pair((char)x, ans));
        }
        sort(v.begin(), v.end(), cmp);
        printf("World #%d\n", cs++);
        for(i=0;i<v.size();++i)
            printf("%c: %d\n", v[i].first, v[i].second);
    }
    return 0;
}
