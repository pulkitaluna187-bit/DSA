class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0;
        int end=height.size()-1;
        int currProd=0;
        int maxProd=0;
        while(st<end){
            int length=min(height[st],height[end]);
            currProd=length*(end-st);
            maxProd=max(maxProd,currProd);
            if(height[st]<height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxProd;
    }
};