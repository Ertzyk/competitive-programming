#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, to_delete = 1, result = 0;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < 2*n; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            st.push(x);
        } else {
            if(!st.empty()){
                if(st.top() == to_delete) st.pop();
                else {
                    while(!st.empty()) st.pop();
                    result++;
                }
            }
            to_delete++;
        }
    }
    cout << result << '\n';
    return 0;
}