#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t, u;
    cin >> s;
    for(int i = 0; i < 26; i++){
        bool found_letter = false;
        stack<char> t_stack;
        string s2;
        while(!t.empty() && t.back() - 'a' <= i){
            u += t.back();
            t.pop_back();
        }
        for(int j = s.size() - 1; j >= 0; j--){
            if(s[j] - 'a' == i){
                found_letter = true;
                u += (char)(i + 'a');
            } else if(found_letter){
                t_stack.push(s[j]);
            } else {
                s2 += s[j];
            }
        }
        reverse(s2.begin(), s2.end());
        s = s2;
        while(!t_stack.empty()){
            t += t_stack.top();
            t_stack.pop();
        }
    }
    cout << u << '\n';
    return 0;
}