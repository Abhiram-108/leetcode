class Solution {
public:
    string strWithout3a3b(int a, int b) {
          string ans;
        int n = a + b;
        int i = 0, acount = 0, bcount = 0;
        while(i < n){
            if(b > a){
                if(bcount < 2 && b > 0){
                    ans.push_back('b');
                    b--; bcount++;
                    acount = 0;
                }   
                else if(a > 0 && acount < 2){
                    ans.push_back('a');
                    a--; acount++;
                    bcount = 0;
                }
                i++;
            }

            else{
                if(a > 0 && acount < 2){
                    ans.push_back('a');
                    a--; acount++;
                    bcount = 0;
                }
                else if(bcount < 2 && b > 0){
                    ans.push_back('b');
                    b--; bcount++;
                    acount = 0;
                }
                i++;
            }
        }

        return ans;
        
    }
};