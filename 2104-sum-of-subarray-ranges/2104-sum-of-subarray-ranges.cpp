class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();

        vector<int> prevSmall(n), nextSmall(n);
        vector<int> prevGreat(n), nextGreat(n);

        stack<int> st;

        // Next Smaller
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous Smaller
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Greater
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            nextGreat[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous Greater
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            prevGreat[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long minContribution =
                1LL * arr[i] * (i - prevSmall[i]) * (nextSmall[i] - i);

            long long maxContribution =
                1LL * arr[i] * (i - prevGreat[i]) * (nextGreat[i] - i);

            ans += maxContribution - minContribution;
        }

        return ans;
    }
};