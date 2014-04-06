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

#define MAX 1<<15
bitset<MAX> bs;
vi primes;
int ans[MAX], i, j, n;

int main()
{
    bs.set(), primes.clear();
    bs[1]=bs[0]=0;
    for(i=2;i<MAX;++i)
    {
        if(bs[i])
        {
            for(j=i*i;j<MAX;j+=i)
                bs[j]=0;
            primes.push_back(i);
        }
    }
    for(i=0;i<(int)primes.size();++i)
        for(j=i;j<(int)primes.size();++j)
            if(primes[i]+primes[j]<MAX)
                ans[primes[i]+primes[j]]++;
            else
                break;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        printf("%d\n", ans[n]);
    }
    return 0;
}
