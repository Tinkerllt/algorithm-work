#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<set>
#include<deque>
#include<queue>
#include<vector>
//#include<unordered_map>
#include<map>
#include<stack>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define Pii pair<ll,int>
#define m_p make_pair
#define l_b lower_bound
#define u_b upper_bound 
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 300 + 11;
const int maxm = 600 + 11;
const int mod = 1e9 + 7;
const double eps = 1e-5;
ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b, ll p) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= p; }b >>= 1; a = a * a%p; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//iterator 
//head
//priority_queue
int a[maxn][maxn], dp[maxn][maxn]; 
int main() {
	int n,m;
	while (cin>>n>> m) {
		for (int i = 1; i <= n; i++) {
			a[i][0] = 0;
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = 0;
				for (int k = 0; k <= j; k++) {
					if (dp[i][j] < a[i][k] + dp[i - 1][j - k]) {
						dp[i][j] = a[i][k] + dp[i - 1][j - k];
					}
				}
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}

