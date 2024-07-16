// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4


// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

// Solution:=>


class Solution {
public:
vector<int> NSL(vector<int>& heights){
    int n = heights.size();
    vector<int> index_NSL(n);
    stack<int> st;
    index_NSL[0] = -1;
    st.push(0);

    for(int i=1;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
        index_NSL[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return index_NSL;
}

vector<int> NSR(vector<int>& heights){
    int n = heights.size();
    vector<int> index_NSR(n);
    stack<int> st;
    index_NSR[n-1] = n;
    st.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
        index_NSR[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return index_NSR;
}

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> index_NSL = NSL(heights);
         vector<int> index_NSR = NSR(heights);
         int res =0;
         for(int i=0;i<n;i++){
              int height = heights[i];
              int width = index_NSR[i]-index_NSL[i]-1;
              int area = height*width;
                if(area>res){
                    res = area;
                }
         }  return res;
    } 
};
