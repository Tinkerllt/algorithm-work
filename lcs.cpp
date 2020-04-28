#include<stdio.h>
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
const int maxn = 3e5 + 11;
const int maxm = 600 + 11;
const int mod = 1e9 + 7;
const double eps = 1e-5;
inline ll rd() { ll x = 0, f = 1; char ch = getchar(); while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }return x * f; }
inline ll qpow(ll a, ll b, ll p) { ll res = 1; while (b) { if (b & 1) { res *= a; res %= p; }b >>= 1; a = a * a%p; }return res; }
inline ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a%b); }
//iterator
//head
//priority_queue
int c[maxm][maxm];
char b[maxm][maxm];
void lcs(string x, string y){
	int m = x.length();
	int n = y.length();
	for (int i = 1; i <= m; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (x[i - 1] == y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'a';
			}
			else if (c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i - 1][j];
				b[i][j] = 'b';
			}
			else{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'c';
			}
		}
	}
}
 
void print_lcs(string x,int m, int n)
{
	if (m == 0 || n == 0)
		return;
	if (b[m][n] == 'a'){
		print_lcs(x,m - 1, n - 1);
		cout << x[m-1];
	}
	else if (b[m][n] == 'b'){
		print_lcs(x, m - 1, n);
	}
	else
		print_lcs(x, m, n - 1);
}
int main()
{
	string x, y;
	cin >> x >> y;
	lcs(x, y);
    print_lcs(x,x.length(), y.length());
}
