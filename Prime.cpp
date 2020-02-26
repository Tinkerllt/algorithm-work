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
const int maxn = 3e6 + 11;
const int maxm = 2e3 + 11;
const int mod = 1e9 + 7;
const double eps = 1e-5;
ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= mod; }b >>= 1; a = a * a%mod; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//iterator 
//head
int vis[maxm], n, m, ans;
int mp[maxm][maxm],dis[maxm];
void Prime(int cur) {
	ans = 0;
	vis[cur]=1;
	for(int i=1;i<=n;i++){
		dis[i]=mp[cur][i];
	}
	for (int i = 1; i < n; i++) {
		int minn=inf,index;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				minn=dis[j];
				index=j;
			}
		}
		vis[index]=1;
		ans+=minn;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&mp[index][j]<dis[j]){
				dis[j]=mp[index][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) ans=-1;
	}
}
void init(){
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	memset(mp,inf,sizeof mp);
}
int main() {
	while (cin>>m && m != 0) {
		n = rd();
		init();
		for (int i = 1; i <= m; i++) {
			int x=rd(),y=rd(),v=rd();
			if(mp[x][y]>v){
				mp[x][y]=v;
			    mp[y][x]=v;
			}
		}
		Prime(1);
		if (ans == -1) cout << "?" << '\n';
		else cout << ans << '\n';
	}
}
