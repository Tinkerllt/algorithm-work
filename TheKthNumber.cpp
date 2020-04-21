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
	/*实现一次快速排序*/
	int l = right - low + 1;
	if (l == k) //若key处恰好为第k大数，直接返回
		return key;
	else if (l < k)
		/*l<k说明第k大数在key左边序列中，此时为第k-l大的数*/
		FindKthMax(list, left, low - 1, k - l);
	else
		/*l>k说明第k大的数在右边序列中，位置还是第k大的数*/
		FindKthMax(list, low + 1, right, k);
}
