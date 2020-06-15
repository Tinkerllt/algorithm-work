#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include<cstdio>
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
const int maxn = 2e5 + 11;
const int maxm = 20;
const int mod = 1000000007;
const double eps = 1e-5;
inline ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b, ll p) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= p; }b >>= 1; a = a * a%p; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//template<class T> void read(T&num) { char CH; bool F = false; for (CH = getchar(); CH<'0' || CH>'9'; F = CH == '-', CH = getchar()); for (num = 0; CH >= '0'&&CH <= '9'; num = num * 10 + CH - '0', CH = getchar()); F && (num = -num); }
//void print(__int128 x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9) print(x / 10); putchar(x % 10 + '0'); }
//iterator
//head
//priority_queue
//高斯消元  
double ans,center[maxm];//center[maxm]全排列时指每个圆的圆心坐标 
int n,r[maxm],dos[maxm]; 
void cal(){//计算此排列下矩形长度 
	double left=0,right=0;
	for(int i=0;i<n;i++){
		left=min(left,center[i]-r[i]);
		right=max(right,center[i]+r[i]);
	}
	if(ans>right-left) {
		ans=right-left;
		for(int i=0;i<n;i++) dos[i]=r[i];
	}
	return;
}
double cal_center(int t){
	double centerx=0;
	for(int i=0;i<t;i++){//取之前排列圆里面相切最大的x坐标，其余计算出来的坐标必定和之前某个圆的相交 
		centerx=max(centerx,center[i]+2.0*sqrt(r[t]*r[i]));
	}
	return centerx;
}
void dfs(int x)
{
    if(x==n){
        cal();
        return;
	}
    for(int i=x;i<n;i++){//回溯法排列树 
	  	swap(r[x],r[i]);
	  	double y=cal_center(x);
	  	if(y+r[1]+r[x]<ans) center[x]=y,dfs(x+1);//剪枝，若此时 圆心加半径的长度已经比最小长度大则没必要继续搜索 
	  	swap(r[x],r[i]);
 	}
}
int main()
{
    n=rd();
    ans=inf;
    for(int i=0;i<n;i++) r[i]=rd();
//    sort(r,r+n,greater<int>()); 感觉有序无序对于剪枝影响不大 
	dfs(0);
	printf("%lf\n",ans);
	for(int i=0;i<n;i++) printf("%d ",dos[i]);//输出半径排列 
	puts("");
	return 0;
}
