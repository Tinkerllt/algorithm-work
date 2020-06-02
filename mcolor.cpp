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
const int maxm = 1e3 + 11;
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
int n,m;
int a=1,b=1;
int cou=0;
int graph[20][20]={0};
int color[20]={0};
bool ok(int c){
    for(int k=1;k<=n;k++){
        if(graph[c][k]&&color[c]==color[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int cur){
    if(cur>n){
        for(int i=1;i<=n;i++){
            printf("%d ",color[i]);
        }
        cou++;
        printf("\n");
    }else{
        for(int i=1;i<=m;i++){
            color[cur]=i;
            if(ok(cur)){
                backtrack(cur+1);
            }
            color[cur]=0;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    while(scanf("%d %d",&a,&b)!=EOF&&a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;
    }
    backtrack(1);
    printf("Total=%d",cou);
    return 0;
}
