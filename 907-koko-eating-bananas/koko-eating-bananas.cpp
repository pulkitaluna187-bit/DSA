class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int st=1;
        int end=maxi;
        while(st<=end){
        long long  totalHours=0;
            int mid= st+(end-st)/2;
            for(int i=0;i<n;i++){
                 totalHours += ceil((double) piles[i]/(double)mid);
            }
            if(totalHours<=h){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};