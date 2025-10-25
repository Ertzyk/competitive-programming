#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, cur = 0;
        string s;
        cin >> n >> s;
        stack<int> stk0, stk1;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(stk0.empty()){
                    cur++;
                    res[i] = cur;
                    stk1.push(cur);
                } else {
                    int x = stk0.top();
                    stk0.pop();
                    res[i] = x;
                    stk1.push(x);
                }
            } else {
                if(stk1.empty()){
                    cur++;
                    res[i] = cur;
                    stk0.push(cur);
                } else {
                    int x = stk1.top();
                    stk1.pop();
                    res[i] = x;
                    stk0.push(x);
                }
            }
        }
        cout << cur << '\n';
        for(int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
    }
    return 0;
}