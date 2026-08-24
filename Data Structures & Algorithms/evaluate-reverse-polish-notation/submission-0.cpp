class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            string token=tokens[i];
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(token=="+"){
                    s.push(a+b);
                }
                else if(token=="-"){
                    s.push(a-b);
                }
                else if(token=="*"){
                    s.push(a*b);
                }
                else{
                    s.push(a/b);
                }
            }
            else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
