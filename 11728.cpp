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

int n, tmp, i, j, cs=1;
int ans[1010];

int sum(int x)
{
    int res=0;
    for(j=1;j<=sqrt(x);++j)
    {
        if(x%j==0)
        {
            res+=j;
            if(x/j!=j)
                res+=(x/j);
        }
    }
    return res;
}

int main()
{
    memset(ans, -1, sizeof ans);
    for(i=1;i<=1000;++i)
    {
        tmp=sum(i);
        if(tmp<=1000)
            ans[tmp]=i;
    }
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        printf("Case %d: %d\n", cs++, ans[n]);
    }
    return 0;
}
