class Solution {
    private:
  
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
         int n = score.size();
        int m = score[0].size();

        sort(score.begin(), score.end(),[k](vector<int> a,vector<int> b)
        {
            return a[k] > b[k];
        });
        return score;
      
       
    }
};