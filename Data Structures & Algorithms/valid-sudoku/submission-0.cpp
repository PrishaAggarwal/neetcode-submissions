class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //My logic says i could use hashmap to keep the count rowwise first and if anything repeats then return false and so on...
        //but my mistake i got hint from chagpt that using unordered_Set is easier since we only have to check the existance
        int i=0;
        int j=0;
        unordered_set<char>rows; //char because '.' is also used and it isnt counter under int
        unordered_set<char>cols;
        unordered_set<char>grid;
        int n=board.size();
        //here even though i pass through whole gird that is O(n^2) but since sudoko is fixed at 9*9 so complexity is 81
        for(i=0;i<n;i++){
            rows.clear();
            for(j=0;j<n;j++){
                //we have to ignore the '.' and ek baar insert hone ke baad if they come again then they create duplicate and returning false;
                if(rows.find(board[i][j]) == rows.end()){
                    rows.insert(board[i][j]);
                }
                else{
                    if(board[i][j] == '.')
                        continue;
                    else 
                        return false;
                }
            }
        }
        for(j=0;j<n;j++){
            cols.clear();
            for(i=0;i<n;i++){
                if(cols.find(board[i][j]) == cols.end()){
                    cols.insert(board[i][j]);
                }
                else{
                    if(board[i][j] == '.')
                        continue;
                    else 
                        return false;
                }
            }
        }
        //now i have to check the small grid boxes
        //for that i am thinking to make total 3 rows and 3 cols in whole sudoko
        // we jump to next official row/col when 3 of sudoko's rows/col are finished
        //The logic i wrote before code is right and try and implement that only
        //its ohk if it takes extra loops since its complexity wont increase
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                //now i will check the grid by just checking whole jth col in this grid
                int m=i+3;
                int s=j+3;
                for(int p=j;p<s;p++){
                    for(int q=i;q<m;q++){
                        if(grid.find(board[p][q]) == grid.end()){
                            grid.insert(board[p][q]);
                        }
                        else{
                            if(board[p][q] == '.')
                                continue;
                            else 
                                return false;
                        }
                    }
                }
                grid.clear();
            }
        }
        return true;
    }
};
