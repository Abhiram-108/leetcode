class Solution {
    private:
    int solve(int n){
        switch(n&3){
            case 0:
                return n;
            case 1:
                return 1;
            case 2:
                return n+1;
            case 3:
                return 0;
                
            
        }
        return 0;
        
    }
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>ans;
        int xor_enc=0;
        int n=encoded.size()+1;
        for(int i=0;i<encoded.size();i+=2){
            xor_enc^=encoded[i];
        }
        int value=xor_enc ^ solve(n);
        ans.push_back(value);
        for(int i=n-2;i>=0;i--){
            value=encoded[i] ^ value;
            ans.push_back(value);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};