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

int n;
set<ll> st;
vector<ll> v;

int main()
{
    st.insert((ll)1);
    set<ll>::iterator it=st.begin();
    while(st.size()<=10000)
    {
        st.insert(*it*(ll)2);
        st.insert(*it*(ll)3);
        st.insert(*it*(ll)5);
        st.insert(*it*(ll)7);
        ++it;
    }
    v.clear();
    v.assign(st.begin(), st.end());
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        if(n%100>=11 && n%100<=13)
            printf("The %dth humble number is %lld.\n", n, v[n-1]);
        else
        {
            printf("The %d%s humble number is %lld.\n", n, (n%10==1)?"st":((n%10==2)?"nd":(((n%10)==3)?"rd":"th")), v[n-1]);
        }
    }
    return 0;
}
