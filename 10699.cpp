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

map<int, int> mp;
int n, ans, t;
ll i;

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        if(mp.count(n))
        {
            printf("%d\n", mp[n]);
            continue;
        }
        ans=0;
        t=n;
        for(i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                ans++;
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1)
            ans++;
        mp[n]=ans;
        printf("%d : %d\n", t, ans);
    }
    return 0;
}
