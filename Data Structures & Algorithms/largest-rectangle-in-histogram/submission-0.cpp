class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>store;
        int maxarea=0;
        int n=heights.size();
        int i=0;
        if(n==1)
            return heights[0];
        for(i=0;i<n;i++){
            if(store.empty()){
                store.push({i,heights[i]});
            }
            else if(heights[i]<store.top().second){
                int index=-1;
                while(!store.empty() && heights[i]<=store.top().second){
                    int width=i-store.top().first;
                    //ismein +1 isliye nhi because humne jo abhi encounter kra hai osko count nhi krna
                    int height=store.top().second;
                    index=store.top().first;
                    //kyuki since we encountered chotti value so this chotti value can be extended till what is on top of stack
                    if(maxarea<height*width)
                        maxarea=height*width;
                    store.pop();
                }
                store.push({index,heights[i]});
            }
            else{
                store.push({i,heights[i]});
            }
        }
        if(!store.empty()){
            //now stack is not empty therefore some heights were valid till end
            //we have to consider them while calculating area
            i=n-1; //i at last index
            while(!store.empty()){
                //ismein +1 hoga since we are at 5th index and we need to count it also since we have reached till end
                int width=i-store.top().first+1;
                int height=store.top().second;
                if(maxarea<width*height)
                    maxarea=width*height;
                store.pop();
            }
        }
        return maxarea;
    }
};
