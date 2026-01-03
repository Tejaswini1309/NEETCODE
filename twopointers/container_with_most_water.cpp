class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxarea=0;
        // in this problem first we put our max area as the area possible
        // between the last elemts , then using two pointers i initially at 0
        // and j initially at size-1 we calcualte the area possible with
        // this coordinates possible then move toward the taller one of
        // these two indexes as you are already compromising your width
        // so you would want a better height . repeat this until i and j cross over.
        while(i<=j){
            int width = j-i;
            int height = min(heights[j],heights[i]);
            maxarea=max(maxarea,height*width);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                --j;
            }
        }
        return maxarea;
    }
};