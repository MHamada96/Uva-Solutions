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

char s[15][33];
int c[15];
int ans, mn, i, n, j, t;

int main()
{
    while(1)
    {
        scanf("%d", &n);
        getchar();
        if(!n)
            break;
        mn=INF;
        for(i=1;i<=n;++i)
        {
            gets(s[i]);
            t=0;
            for(j=0;j<25;++j)
                if(s[i][j]==' ')
                    t++;
            c[i]=t;
            mn=min(t, mn);
        }
        ans=0;
        for(i=1;i<=n;++i)
            ans+=c[i]-mn;
        printf("%d\n", ans);
    }
    return 0;
}
