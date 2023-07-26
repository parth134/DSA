class Solution {
public:
    string decodeMessage(string key, string message) {
        int n = key.size();
        map<char,char>m1;
        map<char,char>m2;
        string str = "abcdefghijklmnopqrstuvwxyz";
        string temp="";
        for(int i=0;i<n;i++){
            if(key[i]!=' '){
                temp+=key[i];
            }
        }
        string temp2="";
        for(int i=0;i<temp.size();i++){
            if(!m1[temp[i]]){
                temp2+=temp[i];
                m1[temp[i]]=' ';
            }
        }

        for(int i=0;i<temp2.length();i++){
            m2[temp2[i]]=str[i];
        }
        string ans="";
        for(int i=0;i<message.length();i++){
            if(message[i]!=' '){
                ans+=m2[message[i]];
            }
            else{
                ans+=' ';
            }
        }

        return ans;

    }
};
 