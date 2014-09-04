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
#include <cassert>
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

const int N = 20100;
int n, i;
map<ii, int> mp;
ii p[N];

int solve(int pos, int point) {
	if( pos == n ) 
		return abs(point - p[pos].first) + n - p[pos].first;
	if( mp.count(ii(pos, point) ) != 0 )
		return mp[ii(pos, point)];
	int l = abs(point - p[pos].second) + p[pos].second - p[pos].first + solve(pos + 1, p[pos].first);
	int r = abs(point - p[pos].first) + p[pos].second - p[pos].first + solve(pos + 1, p[pos].second);
	return mp[ii(pos, point)] = min( l, r );
}
int main() {
	while( 1 ) {
		scanf("%d", &n);
		if(!n)
			break;
		mp.clear();
		for( i = 1; i <= n; ++i )
			scanf("%d %d", &p[i].first, &p[i].second);
		printf("%d\n", solve(1, 1) + n - 1);
	}
	return 0;
}
