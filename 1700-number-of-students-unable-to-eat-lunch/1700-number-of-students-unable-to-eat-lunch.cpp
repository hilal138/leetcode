class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& arr) {
        int n =arr.size();
        queue<int>q;
        for(auto ele : students) q.push(ele);
        for(int i=0;i<n;i++){
            if(arr[i]==q.front())q.pop();
            else{
                int k=0;
                while(k<q.size() and arr[i]!=q.front()){
                    int x= q.front();
                    q.pop();
                    q.push(x);
                    k++;
                }
                if(k==q.size()) break;
                q.pop();
            }
        }
        return q.size();
    }
};