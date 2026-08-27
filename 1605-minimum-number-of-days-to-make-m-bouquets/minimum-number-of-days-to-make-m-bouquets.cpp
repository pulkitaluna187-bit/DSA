class Solution {
public:
bool possible(vector<int>& bloomDay, int mid,int m, int k){
    int totalBouq=0;
    int cnt=0;
    for(int i=0;i<bloomDay.size();i++){
        if(mid>=bloomDay[i]){
            cnt++;
        }
        else{   
            totalBouq += cnt/k;
            cnt=0;
        }
    }
    totalBouq += cnt/k;
    return totalBouq>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()< (long long)m*k) return -1;
        
        int minDay=INT_MAX;
        int maxDay=INT_MIN;
        for(int day : bloomDay){
            minDay=min(minDay,day);
            maxDay=max(maxDay,day);
        }
        int st = minDay;
        int end=maxDay;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(bloomDay,mid,m,k)){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
       }
};