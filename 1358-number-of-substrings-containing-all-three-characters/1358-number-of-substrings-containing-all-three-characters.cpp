class Solution {
public:
    int numberOfSubstrings(string s) {
        //it's a sliding window technique and 2 pointer menthod
        int l=0,r=0,cnt=0;
       
       // for(int i=0;i<s.size();i++){
       //      int hash[3]={0};
       //     for(int j=i;j<s.size();j++){
       //         hash[s[j]-'a']=1;
       //         if(hash[0]+hash[1]+hash[2]==3)
       //             cnt+=(s.size()-j);
       //         break;
       //     }
       // }
       //  return cnt;
        
        int lastseen[3]={-1,-1,-1};
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt=cnt+(1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }
        }
        return cnt;
    }
};