class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //traversing left to right for this one
        stack<int>indices;
        int n=temperatures.size();
        vector<int>ans(n,0); //isse jo remaining gaps honge would be already zero
        int i=0;
        for(i=0;i<n;i++){
            if(indices.empty()){
                indices.push(i);
            }
            else{
                while(!indices.empty() && temperatures[i]>temperatures[indices.top()]){
                    ans[indices.top()]=i-indices.top();
                    indices.pop();
                }
                indices.push(i);
            }
        }
        return ans;
    }
};
