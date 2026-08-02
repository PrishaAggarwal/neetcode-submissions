class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //I had a realisation via chatgpt that opp pair dont always collide, we have to look into their position that where they are and then see if they are colliding
        //Basically when do 2 asteroids collide, i have to see
        vector<int>ans;
        int n=asteroids.size();
        int i=0;
        stack<int>st;
        // if same direction mein koi chotta aaya then we empty the stack and put the contents of stack into ans
        if(n==1){
            ans.push_back(asteroids[i]);
            return ans;
        }
        for(i=0;i<n;i++){
            if(st.empty() && asteroids[i]<0){
                ans.push_back(asteroids[i]);
            }
            else if(st.empty() && asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                if(st.top()>0){
                    if(asteroids[i]>0){
                        st.push(asteroids[i]);
                    }
                    else{
                        if(abs(asteroids[i])>=abs(st.top())){
                            while(!st.empty() && abs(asteroids[i])>abs(st.top())){
                                st.pop();
                            }
                            //lets say jo negative wala aaya it can either destroy whole stack or at end something would destroy it if whole stack isnt empty
                            //i feel like monostatic stack wont work here as of now
                            if(st.empty()){
                                ans.push_back(asteroids[i]);
                            }
                            if(!st.empty() && abs(asteroids[i])==abs(st.top())){
                                st.pop();
                            }
                        }
                        else if(abs(asteroids[i])<abs(st.top())){
                            continue;
                        }
                    }
                }
            }
        }
        //now if we have non empty stack at end then we have to empty it
        //but now since it will be emptied in reverse manner so we would later reverse it and join it with final ans
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        ans.insert(ans.end(),temp.begin(),temp.end());
        return ans;
    }
};