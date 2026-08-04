class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            int prev=nums[i-1];
            int curr=nums[i];
            while(prev+1<curr){
                ans.push_back(prev+1);
                    prev++;
            }
            }
        
        return ans;
    }
};