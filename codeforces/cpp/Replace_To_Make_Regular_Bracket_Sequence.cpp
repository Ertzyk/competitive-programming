#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<'){
            st.push(s[i]);
        } else {
            if(st.size() == 0){
                cout << "Impossible\n";
                return 0;
            }
            if((s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') ||
            (s[i] == '}' && st.top() != '{') || (s[i] == '>' && st.top() != '<')) ans++;
            st.pop();
        }
    }
    cout << ((st.empty()) ? to_string(ans) : "Impossible") << '\n';
    return 0;
}