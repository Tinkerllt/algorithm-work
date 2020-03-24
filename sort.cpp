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
inline ll qpow(ll a,ll b,ll p){ll res=1;while(b){if(b&1){res*=a;res%=p;}b>>=1;a=a*a%p;}return res;}
inline ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
//iterator 
//head
//priority_queue
int a[maxn];
int main(){
	//std::ios::sync_with_stdio(false);
    int n=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1);
	//检索算法1 遍历
	int m=rd();//检索的数字 
	printf("Case 1:\n");
	for(int i=1;i<=n;i++){
		if(a[i]>m){
			puts("0");
			break;
		}
		if(a[i]==m){
			printf("%d\n",i);
			break;
		}
		if(i==n){
			puts("0");
			break;
		}
	} 
	//二分检索
	printf("Case 2:\n");
	int l=1,r=n; 
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<m) l=mid+1;
		else r=mid-1;
	}
	if(l>n||a[l]!=m) puts("0");
	else printf("%d\n",l);
}

