class Solution {
public:
    vector<int>nse(vector<int>&heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>ans(n, n);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>pse(vector<int>&heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>ans(n, -1);

        for(int i = 0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangle(vector<int>&heights) {
        int n = heights.size();
        vector<int>next = nse(heights);
        vector<int>prev = pse(heights);

        int maxi = 0;
        for(int i = 0; i<n; i++) {
            int width = next[i]-prev[i]-1;
            maxi = max(maxi, heights[i]*width);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>heights(m, 0);
        int maxi = 0;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            maxi = max(maxi, largestRectangle(heights));
        }
        return maxi;
    }
};