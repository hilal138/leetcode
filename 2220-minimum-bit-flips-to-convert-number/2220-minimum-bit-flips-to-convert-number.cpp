class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(start>0 or goal>0){
            if((start%2==0 and goal%2!=0)or (start%2!=0 and goal%2==0)) count++;
            start=start>>1;
            goal=goal>>1;
        }
        return count;
    }
};