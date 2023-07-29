class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>stk;
        if(n==1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push('(');
            }
            if(s[i]=='{'){
                stk.push('{');
            }
            if(s[i]=='['){
                stk.push('[');
            }
            if(s[i]==')'){
                if(stk.empty() || stk.top()!='('){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
            if(s[i]==']'){
                if(stk.empty() || stk.top()!='['){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
            if(s[i]=='}'){
                if(stk.empty() || stk.top()!='{'){
                    return false;
                }
                else{
                    stk.pop();
                }
                
            }
            
        }
        if(stk.empty()){
            return true;
        }

        return false;
    }
};