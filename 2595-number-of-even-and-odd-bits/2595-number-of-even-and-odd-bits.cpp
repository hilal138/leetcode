class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0;
        int odd=0;
        int idx=0;
        while(n>0){
            if(n%2!=0 and idx%2==0) even++;
            if(n%2!=0 and idx%2!=0) odd++;
            n=n>>1;
            idx++;
        }
        return {even,odd};
    }
};