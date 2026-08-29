class Solution {
public:
    bool noOfDays(vector<int>& weights, int days, int mid){
        int sum=0;
        int cnt=0;
        for(int i=0;i<weights.size();i++){
            if(sum+ weights[i]<=mid){
                sum +=weights[i];
            }
            else{
                cnt++;
                sum=weights[i];
            }
            
        }
        cnt++;
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int st=0;
        int end=0;
        for(int i=0;i<n;i++){
            st= max(st,weights[i]);
            end += weights[i];
        }
        
        while(st<=end){
            int mid= (st+end)/2;
            if(noOfDays(weights,days,mid)){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};