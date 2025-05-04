#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<char> stack;
    for(char x: s){
        if(stack.empty() || (stack.back() != x)){
            stack.push_back(x);
        } else {
            stack.pop_back();
        }
    }
    cout << (stack.empty() ? "Yes" : "No");
    return 0;
}