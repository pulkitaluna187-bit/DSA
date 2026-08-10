class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0,sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int val = sum - k;
            if(m.find(val)!=m.end()){
                count += m[val];
            }
            m[sum]++;
        }
        return count;
    }
};