class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int next[n];
        // next smaller idx elements array 
        next[n-1]=n;   // change
        st.push(n-1);  // change
        for(int i=n-2;i>=0;i--){
        while(st.size()>0 && heights[st.top()]>=heights[i]) st.pop();
        if(st.size()==0) next[i]=n;
        else next[i]=st.top();
        st.push(i);
        }

        // previous index  greatest elements array
        int prev[n];
        stack<int>gt;
        prev[0]=-1;
        gt.push(0);
        for(int i=1;i<n;i++){
        while(gt.size()>0 && heights[gt.top()]>=heights[i]) gt.pop();
        if(gt.size()==0) prev[i]=-1;
        else prev[i]=gt.top();
        gt.push(i);
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int b= next[i]-prev[i]-1;
            int area=h*b;
            maxArea=max(maxArea,area);

        }
        return maxArea;
        
    }
};