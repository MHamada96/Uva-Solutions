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

char s[1010];
int sum, i, n;

int main()
{
    while(1)
    {
        scanf("%s", s);
        if(strcmp(s, "0")==0)
            break;
        sum=0;
        for(i=0;i<strlen(s);++i)
            if(i%2)
                sum+=s[i]-'0';
            else
                sum-=s[i]-'0';
        sum=abs(sum);
        if(sum%11==0)
            printf("%s is a multiple of 11.\n", s);
        else
            printf("%s is not a multiple of 11.\n", s);
    }
    return 0;
}
