class Solution {
public:
    bool checkValidString(string s) {
    //    stack<int> starIndex;
    //     stack<int> stackIndex;

    //     for(int i = 0; i < s.length(); i++)
    //     {
    //         if(s[i] == '(')
    //         {
    //             stackIndex.push(i);
    //         }
    //         else if(s[i] == '*')
    //         {
    //             starIndex.push(i);
    //         }
    //         else if(s[i] == ')')
    //         {
    //             if(stackIndex.empty() && starIndex.empty()) 
    //                 return false;
    //             else if(!stackIndex.empty()) 
    //                 stackIndex.pop();
    //             else    
    //                 starIndex.pop();;
    //         }
    //     }

    //     while(!stackIndex.empty())
    //     {
    //         if(starIndex.empty()) return false;
    //         if(stackIndex.top() > starIndex.top()) return false;
    //         stackIndex.pop();
    //         starIndex.pop();
    //     }

    //     return true;

    int mini=0,maxi=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(')
        {
            mini=mini+1;
            maxi+=1;
        }
        else if(s[i]==')'){
            maxi-=1;
            mini-=1;
        }
        else{
            mini-=1;
            maxi+=1;
        }
        if(mini<0)
        mini=0;
        if(maxi<0)
        return 0;
    }
    return mini==0;
       
     
        
    }
};