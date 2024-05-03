class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1=v1.size();
        int n2=v2.size();
        int a=0;
        int b=0;
        for(int i=0,j=0;i<n1 || j<n2; i++,j++){
            while(i<n1 && v1[i]!='.'){
                a=a*10+(v1[i++]-'0');
                
            }
             while(j<n2 && v2[j]!='.'){
                b=b*10+(v2[j++]-'0');
                
            }
            if(a<b)
                return -1;
            else if(a>b)
                return 1;
            //we have to check each version...
            a=0;
            b=0;
            
        }
        return 0;
        
    }
};