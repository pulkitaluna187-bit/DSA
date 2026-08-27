class Solution {
public:
bool possible(vector<int>& nums, int threshold,int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum += ceil((double)nums[i]/(double)mid);

    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st=1;
        int end=0;
        for(int i=0;i<nums.size();i++){
        end=max(end,nums[i]);
        }

        while(st<=end){
            int mid= (st+end)/2;
            if(possible(nums, threshold, mid)) end=mid-1;
            else {
                st=mid+1;
            }
        }
        return st;
    }
};