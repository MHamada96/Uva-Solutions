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

int x, s;
multiset<int> st;

int main()
{
    st.clear();
    multiset<int>::iterator it;
    while(scanf("%d", &x)!=EOF)
    {
        st.insert(x);
        ++s;
        it=st.begin();
        if(s&1)
        {
            advance(it, s/2);
            printf("%d\n", *it);
        }
        else
        {
            advance(it, s/2-1);
            printf("%d\n", (*it++ +*it)/2);
        }
    }
    return 0;
}
