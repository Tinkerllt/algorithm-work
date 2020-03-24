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
void merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//�󲿷����������Ԫ�صĸ���
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //�Էֱ��Ѿ��ź�������������������кϲ�
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
}
void merge_sort(int *data, int start, int end, int *result)
{
    if(1 == end - start)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//���ֻ��һ��Ԫ�أ���������
        return;
    else
    {
        //�������������䣬�ֱ�������������������
        merge_sort(data,start,(end-start+1)/2+start,result);
        merge_sort(data,(end-start+1)/2+start+1,end,result);
        //��ʼ�鲢�Ѿ��ź����start��end֮�������
        merge(data,start,end,result);
        //���������������ݸ��Ƶ�ԭʼ������ȥ
        for(int i = start;i <= end;++i)
            data[i] = result[i];
    }
}
int main(){
	//std::ios::sync_with_stdio(false);
    int n=rd();
    int data[100];
    int result[100];
    for(int i=0;i<n;i++){
    	data[i]=rd();
	}
    cout << "Before sorted:" << endl;
    for(int i = 0;i < n;++i)
        cout << data[i] << "  ";
    cout << endl;
    cout << "After sorted:" << endl;
    merge_sort(data,0,n-1,result);
    for(int i = 0;i < n;++i)
        cout << data[i] << "  ";
    cout << endl;
}

