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
#define Pii pair<ll,ll>
#define m_p make_pair
#define l_b lower_bound
#define u_b upper_bound 
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5 + 11;
const int maxm = 2e3 + 11;
const int mod = 1e9 + 7;
const double eps = 1e-5;
ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= mod; }b >>= 1; a = a * a%mod; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//iterator 
//head
int fa[maxn], n, m, ans;
struct node {
	int from, to, val;
	bool operator <(const node &a) {
		return this->val < a.val;
	}
}tree[maxn];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
bool same(int x, int y) {
	return find(x) == find(y);
}
void Kruskal() {
	ans = 0;
	for (int i = 1; i <= m; i++) {
		if (same(tree[i].from, tree[i].to)) continue;
		ans += tree[i].val;
		merge(tree[i].from, tree[i].to);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) ++count;
	}
	if (count > 1) ans = -1;
}
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}
int main() {
	while (cin>>m && m != 0) {
		n = rd();
		init();
		for (int i = 1; i <= m; i++) {
			tree[i].from = rd();
			tree[i].to = rd();
			tree[i].val = rd();
		}
		sort(tree + 1, tree + m + 1);
		Kruskal();
		if (ans == -1) cout << "?" << '\n';
		else cout << ans << '\n';
	}
}
