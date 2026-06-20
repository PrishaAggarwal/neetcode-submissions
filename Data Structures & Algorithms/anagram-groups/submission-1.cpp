class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //LOGIC 1
        /*
        int i=0;
        int j=0;
        int n=strs.size();
        vector<unordered_map<char,int>>word(n);
        for(i=0;i<n;i++){
            for(j=0;j<strs[i].size();j++){
                word[i][strs[i][j]]++;
            }
        }
        vector<vector<string>> ans;
        //i am going to introduce another vector hashmap to store unique words that represent each row in ans
        ans.push_back({strs[0]});
        vector<unordered_map<char,int>>unique;
        //since i dont know the exact length in unique and elements cant be directly added to unique without it having any element so i do the following
        unique.push_back({}); // i created a hashmpa in this and now its not empty
        for(i=0;i<strs[0].size();i++){
            //i am storing 1st word of strs in unique
            unique[0][strs[0][i]]++;
        }
        //now keys of unique represent rows of ans
        for(i=1;i<n;i++){
            int m=unique.size();
            bool valid=false;
            for(j=0;j<m;j++){
                if(word[i]==unique[j]){
                    ans[j].push_back({strs[i]});
                    valid=true;
                    break;
                }
            }
            if(!valid){
                //unique[m]=word[i]; //copying another unique word
                // the above line cannot be used because m does not exist yet so we just add the new hashamp to the end
                unique.push_back(word[i]);
                ans.push_back({strs[i]});
            }
        }
        return ans;
        */
        //LOGIC 2
        unordered_map<string,vector<string>> groups;

        for(auto& word : strs){
            int count[26]= {0};
            for(char c:word){
                count[c-'a']++;
                //above is trick used for an array index 0-25
                /// 'a' - 'a' =0
                // 'b' - 'a' = 1
                //'c' - 'a' = 2         
            }
            //now we convert the 26 length count array into string
            string key;
            for(int i=0;i<26;i++){
                key += '#';
                key += to_string(count[i]);
            }
            groups[key].push_back(word);
        }
        //now we combine all the values into group for ans
        vector<vector<string>>ans;
        for(auto& p:groups){
            ans.push_back(p.second);
        }
        return ans;
    }
};
