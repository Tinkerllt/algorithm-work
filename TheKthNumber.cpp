#include<iostream>
using namespace std;
int FindKthMax(int*list, int left, int right, int k);
int main() {
	int i,n,k;
	while (cin >> n) {
		int *a = new int[n];
		for (i = 0; i < n; i++)
			cin >> a[i];
		cin >> k;
		cout << FindKthMax(a, 0, n - 1, k) << endl;
	}
	return 0;
}
int FindKthMax(int*list, int left, int right, int k) {
	int key = list[left];
	int low = left, high = right;
	while (low < high) {
		while (list[high]>=key&&high > low)
			high--;
		list[low] = list[high];
		while (list[low]<=key&&high>low)
			low++;
		list[high] = list[low];
	}
	list[low] = key;
	/*ʵ��һ�ο�������*/
	int l = right - low + 1;
	if (l == k) //��key��ǡ��Ϊ��k������ֱ�ӷ���
		return key;
	else if (l < k)
		/*l<k˵����k������key��������У���ʱΪ��k-l�����*/
		FindKthMax(list, left, low - 1, k - l);
	else
		/*l>k˵����k��������ұ������У�λ�û��ǵ�k�����*/
		FindKthMax(list, low + 1, right, k);
}
