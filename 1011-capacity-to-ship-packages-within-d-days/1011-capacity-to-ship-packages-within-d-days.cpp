class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int lo = INT_MIN;
        int hgh=0;
        for(auto ele : arr){
            lo=max(lo,ele);
            hgh+=ele;
        }
        int ans=hgh;
        while(lo<=hgh){
            int mid = lo + (hgh-lo)/2;
             int currdays=1;
             int currweight=0;
            for(auto ele : arr){
                if(currweight+ele <= mid) currweight+=ele;
                else{
                    currdays++;
                    currweight=ele;
                }
            }
            if(currdays<=days){
                ans=mid;
                hgh=mid-1;
            }
            else lo=mid+1;
        } 

        return ans;   
    }
};