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
int mp[maxm][maxm];//ÁÚ½Ó¾ØÕó´æÍ¼ 
int main(){
    int n=rd(),m=rd();
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {if(i==j) continue;mp[i][j]=inf;}
	for(int i=1;i<=m;i++){
		int s=rd(),e=rd(),v=rd();
		mp[s][e]=v;//ÓÐÏòÍ¼ 
	} 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);//ËÉ³Ú²Ù×÷ 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			printf("st-%d ed-%d:len-%d\n",i,j,mp[i][j]==inf?-1:mp[i][j]);
		}
	} 
} 
/*4 8
1 2 2
2 3 3
1 3 6
3 1 7
1 4 4
4 1 5
4 3 12
3 4 1*/



