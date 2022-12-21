#include <bits/stdc++.h>
#define MaxN 1000001
using namespace std;
int const MOD = 1e9 + 7;
int n, a[MaxN];
int tmp[MaxN];

// Merge 2 sorted arrays and returns inversion count of arrays
int mergeParts(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, invCnt = 0;
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            invCnt = (invCnt + (mid - i + 1)) % MOD;
        }
    }
    // Copy remaining elements of left sub-array (if any) to tmp
    while (i <= mid) tmp[k++] = a[i++];
    // Copy remaining elements of right sub-array (if any) to tmp
    while (j <= right) tmp[k++] = a[j++];
    // Copy merged elements back to original array
    for (i = left; i <= right; i++) a[i] = tmp[i];
    return invCnt;
}

// Recursively sort array and returns inversion count of array
int mergeSort(int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        // Divide array into 2 parts and call mergeSort() for each part
        mid = (right + left) / 2;
        // Inversion count is sum of inversions of left-part, right-part and
        // inversions in merging
        inv_count = (inv_count + mergeSort(left, mid)) % MOD;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
        inv_count = (inv_count + mergeParts(left, mid, right)) % MOD;
    }
    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cout << mergeSort(1, n);
    return 0;
}
