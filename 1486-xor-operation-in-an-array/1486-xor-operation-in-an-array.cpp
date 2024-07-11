class Solution {
public:
    int xorOperation(int n, int start) {
        int xor_enc=0;
      
        for(int i=0;i<n;i++){
            xor_enc^=start+2*i;
            
        }
        return xor_enc;
        
        
        
    }
};