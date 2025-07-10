class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<bool>>row(9,vector<bool>(9,false));
        vector<vector<bool>>col(9,vector<bool>(9,false));
        vector<vector<bool>>box(9,vector<bool>(9,false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){continue;}
                if(row[board[i][j]-'1'][i]==true){
                    return false;
                }
                else{
                    row[board[i][j]-'1'][i]=true;
                }
                if(col[board[i][j]-'1'][j]==true){
                    return false;
                }
                else{
                    col[board[i][j]-'1'][j]=true;
                }
                if(box[board[i][j]-'1'][i/3 + (j/3)*3]==true){
                    return false;
                }
                else{
                    box[board[i][j]-'1'][i/3 + (j/3)*3]=true;
                }
            }
        }
        return true;
    }
};