class Solution {
public:
    int value(char r){
        if(r=='I'){
            return 1;
        }
        else if(r=='V'){
            return 5;
        }
        else if(r=='X'){
            return 10;
        }
        else if(r=='L'){
            return 50;
        }
        else if(r=='C'){
            return 100;
        }
        else if(r=='D'){
            return 500;
        }
        else if(r=='M'){
            return 1000;
        }
        else{
            return -1;
        }
    }
    

    int romanToInt(string s) {
        int res=0;
        for(int i=0; i<s.length(); i++){
            int s1=value(s[i]);
            if(i+1<s.length()){
                int s2=value(s[i+1]);
                if(s1>=s2){
                    res+=s1;
                }
                else{
                    res+=(s2-s1);
                    i++;
                }
            }
            else{
                res+=s1;
            }  
        }
        return res;
    }
};