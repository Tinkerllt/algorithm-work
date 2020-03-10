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
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+11;
const int maxm=2e3+11;
const int mod=1e9+7; 
const double eps=1e-5;
ll rd(){ll x = 0, f = 1; char ch = getchar();while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f;}
inline ll qpow(ll a,ll b){ll res=1;while(b){if(b&1){res*=a;res%=mod;}b>>=1;a=a*a%mod;}return res;}
inline ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
//iterator 
//head
priority_queue<pii>q;//从大到小 
int head[maxn],ver[maxn],Next[maxn],cnt,edge[maxn];
int dis[maxn],vis[maxn],n,m;
void addedge(int x,int y,int v){//链式前向星存边 
	Next[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	edge[cnt]=v;
}
void dijkstra(int st){//单元最短路的源这里是1 
	memset(dis,inf,sizeof dis);
	dis[st]=0;
	vis[st]=1;
	q.push(m_p(0,st));
	while(!q.empty()) {
		int x=q.top().second;
		q.pop();
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(vis[y]) continue;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push(m_p(-dis[y],y));
				vis[y]=1;
			}
		}
	}
	for(int i=2;i<=n;i++) printf("1->%d:%d\n",i,dis[i]);
}
int main(){
    n=rd(),m=rd();
    for(int i=1;i<=m;i++){
    	int x=rd(),y=rd(),z=rd();
		addedge(x,y,z); 
	}
    dijkstra(1);
} 
/*8 11
1 2 1
3 1 2
2 4 2
4 3 1
5 4 2
4 6 8
6 5 2
5 7 2
7 6 3
8 6 2
7 8 3*/


