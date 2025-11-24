#include <iostream>
#include <vector>
using namespace std;

// 把 arr[left..mid] 与 arr[mid+1..right] 合并
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左段长度
    int n2 = right - mid;    // 右段长度
    vector<int> L(arr.begin() + left, arr.begin() + left + n1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

    int i = 0, j = 0, k = left; // k 写回原数组
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++]; // 稳定性：<= 取左边
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;                          // 0 或 1 个元素，天然有序
    int mid = left + (right - left) / 2; // 防溢出写法
    mergeSort(arr, left, mid);           // 先排左边
    mergeSort(arr, mid + 1, right);      // 再排右边
    merge(arr, left, mid, right);        // 把两段粘成一段有序
}

int main()
{
    vector<int> v = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42, 35, 17, 8, 99, 23, 67, 45, 78, 33};
    mergeSort(v, 0, v.size() - 1);
    ;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
