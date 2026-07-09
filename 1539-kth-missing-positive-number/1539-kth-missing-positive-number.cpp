class Solution {
public:
    int findKthPositive(vector<int>& arr, int tar) {
        int missing=-1;
        int i=0;
        int j=1;
        int temp=tar;
        while(i<arr.size()){
            if(temp==tar and i == arr.size()-1){
                missing=arr[i]+tar;
            }
            if(temp==0) break;
            if(temp<tar and temp!=0 and i==arr.size()-1){
                missing=arr[i]+temp;
            }
            if(arr[i]-j==0){
                i++;
                j++;
            }
            else{
                missing=j;
                j++;
                temp--;
            }
        }
        return missing;
    }
};