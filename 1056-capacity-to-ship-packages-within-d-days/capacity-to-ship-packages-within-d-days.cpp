class Solution {
public:
    int noOfDays(vector<int>& weights, int days, int mid){
        int sum=0;
        int daysReq=1;
        for(int i=0;i<weights.size();i++){
            if(sum+ weights[i]<=mid){
                sum +=weights[i];
            }
            else{
                daysReq++;
                sum=weights[i];
            }
            
        }
        
        return daysReq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st=*max_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
       
        
        while(st<=end){
            int mid= (st+end)/2;
            if(noOfDays(weights,days,mid)<=days){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};