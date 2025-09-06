class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string orginal=s;
       string str=s;
       str+='*';
       reverse(s.begin(),s.end());
       str+=s;
       vector<int>lps(2*n+1,0);

       int i=0;
       int j=1;
       while(j<str.size()){
        if(str[i]==str[j]){
            lps[j]=i+1;
            i++;
            j++;

        }

        else if(str[i]!=str[j]){
            if(i>0){
                i=lps[i-1];
            }
            else{
                lps[j]=0;
                j++;
            }
        
        }
       }
       int diff=n-lps.back();

       return s.substr(0,diff)+orginal;
    }
};
