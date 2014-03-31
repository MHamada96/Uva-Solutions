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

ll ans[100], n;
int i, l, h, mid, r;

int binar(ll val)
{
    l=1, h=19;
    while(l<=h)
    {
        mid=(l+h)>>1;
        if(ans[mid]==val)
            return mid-1;
        if(ans[mid]>val)
            h=mid-1;
        if(ans[mid]<val)
            l=mid+1, r=l-1;
    }
    return r;
}
int main()
{
    ans[1]=1, ans[2]=2, ans[3]=5;
    for(i=4;;++i)
    {
        ans[i]=((4*(ll)i-2)*ans[i-1])/((ll)i+1);
        if(ans[i]>(ll)4294967295)
            break;
    }
    while(scanf("%lld", &n)!=EOF)
        printf("%d\n", binar(n)+1);
    return 0;
}
