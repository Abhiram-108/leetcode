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
int n=s.size();
   int l=0;
   int r=0;
   for(int i=0;i<n;i++){
    if(s[i]=='('){
        l++;
        r++;
    }
    if(s[i]=='*'){
        l--;
        r++;
    }
    if(s[i]==')'){
        l--;
        r--;
    }

    if(l<0)
    l=0;
    if(r<0)
    return false;

   }
       return l==0;
     
        
    }
};