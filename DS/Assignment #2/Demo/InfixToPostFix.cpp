#include "Stack.cpp"
#include <cctype> //to use isdigit() function

class InfixToPostfix{
private:
    Stack<char> inf;
    bool isHigherPeriority(char x){
        if (x == '*' || x == '/' || x == '^'){
            return true;
        }
        return false;
    }
    bool isLetter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        else {
            return false;
        }
    }

public:
    InfixToPostfix(string exp);
    ~InfixToPostfix();
};

InfixToPostfix::InfixToPostfix(string exp)
{
    for (int i = 0; i < exp.size(); i++){
        if (exp[i] == ' ' ){
            continue;
        }else if (isdigit(exp[i]) || isLetter(exp[i]) ){
            cout<<exp[i]<<" ";
            if (exp.size()-1 == i){
                // cout<<" End";
                while (!inf.isEmpty()){
                    if (inf.top() == '(' || inf.top() == ')'){
                        inf.pop();
                    }else{
                        cout<<inf.pop()<<" ";
                    }
                }
            }
        }else if (inf.isEmpty()){
            inf.push(exp[i]);
            // cout<<endl<<exp[i]<<endl;
        }else if(!inf.isEmpty() && !isLetter(exp[i])){
            if (exp[i] == '(' ){
                inf.push(exp[i]);
            }else if( inf.top() == '(' ){
                inf.push(exp[i]);
            }else if(isHigherPeriority(exp[i]) && !isHigherPeriority(inf.top())){
                //condition of )
                if (exp[i] == ')'){
                while (!inf.isEmpty()){
                    if (inf.top() == '(' || inf.top() == ')'){
                        inf.pop();
                    }else{
                        cout<<inf.pop()<<" ";
                    }
                }
                }else{
                    inf.push(exp[i]);
                    // cout<<exp[i]<<endl;
                }
            }else{
                while (!inf.isEmpty()){
                    if (inf.top() == '(' || inf.top() == ')'){
                        inf.pop();
                    }else{
                        cout<<inf.pop()<<" ";
                    }
                }
                inf.push(exp[i]);
                // cout<<endl<<"isEmpty Now: "<<inf.isEmpty()<<endl;
            }
        }
    }
}

InfixToPostfix::~InfixToPostfix()
{
}

int main(){
    string x =  "X^Y / (5*Z) + 2";
    InfixToPostfix post(x);
}