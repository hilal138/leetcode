class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n= arr.size();
        int low=arr[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(arr[i]<low) low=arr[i];
            profit=max(profit,arr[i]-low);
        }
        return profit;
    }
};