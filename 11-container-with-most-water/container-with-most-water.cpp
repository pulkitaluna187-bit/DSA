class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxProd=0 ,currProd=0;
        int st=0, end=n-1;
        while(st<end){
            int length=min(height[st],height[end]);
            currProd = length *(end-st);
            maxProd=max(maxProd,currProd);
            if(height[st]<height[end]){
                st++;
            }
            else {
                end--;
            }
        }
        return maxProd;
    }
};