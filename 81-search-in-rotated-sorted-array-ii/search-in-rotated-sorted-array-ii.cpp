class Solution {
public:

    bool binarySearch(vector<int>& nums, int si, int ei, int target)
    {
        if (si > ei)
            return false;

        int mid = si + (ei - si) / 2;

        if (nums[mid] == target)
            return true;

        // NEW CONDITION (only for LC 81)
        if (nums[si] == nums[mid] && nums[mid] == nums[ei])
        {
            return binarySearch(nums, si + 1, ei - 1, target);
        }

        // Left half is sorted
        if (nums[si] <= nums[mid])
        {
            if (nums[si] <= target && target < nums[mid])
                return binarySearch(nums, si, mid - 1, target);
            else
                return binarySearch(nums, mid + 1, ei, target);
        }

        // Right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[ei])
                return binarySearch(nums, mid + 1, ei, target);
            else
                return binarySearch(nums, si, mid - 1, target);
        }
    }

    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};