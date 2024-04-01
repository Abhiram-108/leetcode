class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
    bool flag=false;
        int count=0;
        for(int i=n-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') ||s[i]>='A' && s[i]<='Z'){
                flag=true;
                count++;
            }
            else
            {
                if(flag==true)
                    return count;
            }
        }
        return count;
     
        
        
        
    }
};