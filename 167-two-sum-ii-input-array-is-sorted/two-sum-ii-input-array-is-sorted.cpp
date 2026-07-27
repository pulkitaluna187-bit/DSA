class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int st=0;
        int end=numbers.size()-1;
        while(st<=end){
            int sum=numbers[st]+numbers[end];
            if(sum==target){
                ans.push_back(st+1);
                ans.push_back(end+1);
                return ans;
            }
            else if(sum<target){
                st++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};