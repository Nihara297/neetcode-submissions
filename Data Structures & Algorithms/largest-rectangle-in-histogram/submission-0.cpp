class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int ans=0;
        int cur;
        for(int i=0; i<=n; i++){
            if(i==n){
                cur=0;
            }
            else{
                cur=heights[i];
            }
            while(!s.empty() && cur<heights[s.top()]){
                int height=heights[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width=i;
                }
                else{
                    width=i-s.top()-1;
                }
                ans=max(ans, height*width);
            }
            s.push(i);
        }
        return ans;
    }
};
