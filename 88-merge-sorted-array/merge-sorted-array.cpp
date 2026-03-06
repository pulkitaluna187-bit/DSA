class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> merges;
        int i = 0, j = 0;

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                merges.push_back(nums1[i]);
                i++;
            }
            else{
                merges.push_back(nums2[j]);
                j++;
            }
        }

        // remaining elements of nums1
        while(i < m){
            merges.push_back(nums1[i]);
            i++;
        }

        // remaining elements of nums2
        while(j < n){
            merges.push_back(nums2[j]);
            j++;
        }

        for(int k = 0; k < m+n; k++){
            nums1[k] = merges[k];
        }
    }
};