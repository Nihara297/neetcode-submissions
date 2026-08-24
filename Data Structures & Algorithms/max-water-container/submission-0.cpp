class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=n-1;
        int w=0;
        while(l<r){
            int width=r-l;
            int h=min(heights[l],heights[r]);
            int a=width*h;
            w=max(w,a); 
            if(heights[l]<heights[r]){
                l++;
            } 
            else{
                r--;
            }
        }
        return w;
    }
};
