class Solution {
public:
    bool canWeAllocate(vector<int>& arr, int subarrays, int maxSum) {
        int n = arr.size();
        int cntSubarrays = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= maxSum) {
                sum += arr[i];
            } else {
                sum = arr[i];
                cntSubarrays++;
            }
        }
        return (cntSubarrays <= subarrays);
    }
    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
            if (m > n)
                return -1;
            int st = *max_element(arr.begin(), arr.end());
            int end = accumulate(arr.begin(), arr.end(), 0);
            while (st <= end) {
                int mid = (st + end) / 2;
                if (canWeAllocate(arr, m, mid)) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
             return st;   
    }
};