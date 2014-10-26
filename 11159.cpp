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
 
template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 333 ;
const int M = 1e5 ;
int t, n, m, a[N], b[N], pn[N], pm[N], ans, NIL, i, cs = 1;
int q[M], dist[N] ;
vector<int> g[N] ;

bool BFS() {
	int b , en, v, u ;
	b = en = 0;
	for( i = 1; i <= n; ++i ) {
		if( pn[i] == NIL ) {
			dist[i] = 0;
			q[en++] = i ;
		}
		else
			dist[i] = INF ;
	}
	dist[NIL] = INF ;
	while( b < en ) {
		v = q[b++] ;
		if( dist[v] < dist[NIL] ) {
			for( int j = 0; j < (int) g[v].size(); ++j ) {
				u = g[v][j] ;
				if( dist[ pm[u] ] == INF ) {
					dist[ pm[u] ] = dist[v] + 1;
					q[en++] = pm[u] ;
				}
			}
		}		
	}
	return dist[NIL] != INF ;
}

bool DFS(int v) {
	int u ;
	if( v != NIL ) {
		for( int j = 0; j < (int) g[v].size(); ++j ) {
			u = g[v][j] ;
			if( dist[ pm[u] ] == dist[v] + 1 ) {
				if( DFS( pm[u] ) ) {
					pm[u] = v ;
					pn[v] = u ;
					return true ;
				}
			}
		}
		dist[v] = INF ;
		return false; 
	}
	return true ;
}

int Hopcroft_Karp() {
	for( i = 1; i <= n + m + 2; ++i )
		pn[i] = pm[i] = NIL ;
	while( BFS() ) {
		for(i = 1; i <= n; ++i ) {
			if( pn[i] == NIL ) {
				if( DFS(i) ) {
					++ans;
				}
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for( i = 1; i <= m; ++i )
			scanf("%d", &b[i]);
		for( i = 1; i <= n + m; ++i )
			g[i].clear();
		int j ;
		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= m; ++j ) {
				if( a[i] != 0 && b[j] % a[i] == 0 ) {
					g[i].push_back(j + n) ;
				}
				if( a[i] == 0 && b[j] == 0 )
					g[i].push_back(j + n);
			}
		}
		ans = 0;
		printf("Case %d: %d\n", cs++, Hopcroft_Karp());
	}
	return 0;
}
