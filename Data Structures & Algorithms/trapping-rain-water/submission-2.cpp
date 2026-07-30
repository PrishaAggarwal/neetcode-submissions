class Solution {
public:
    int trap(vector<int>& height) {
        //APPROACH 2 USING MONOSTATIC STACK
        stack<int>st;
        int i=0;
        int ht=0;
        int width=0;
        int water=0;
        int current=0;
        int n=height.size();
        if(n==1)
            return 0;
        for(i=0;i<n;i++){
            if(st.empty()){
                if(i==0 && height[0]==0)
                    continue;
                else    
                    st.push(i);
            }
            else if(height[i]>=height[st.top()]){
                while(!st.empty() && height[i]>=height[st.top()]){
                    current=height[st.top()]; //basically iske upar water we are calculating
                    st.pop();
                    if(!st.empty()){
                        ht=min(height[i],height[st.top()])-current;
                        width=i-st.top()-1;
                        water += ht*width;
                    }
                }
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
        return water;
    }
};
