#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int max_val = -1, max_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }
    vector<int> rotated(n);
    int start_idx = (max_idx + 1)%n;
    for(int i = 0; i < n; i++){
        rotated[i] = a[(start_idx + i)%n];
    }
    vector<int> dp(n, 1);
    stack<int> s;
    int max_zachwytow = 1;
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && rotated[s.top()] <= rotated[i]) s.pop();
        if(!s.empty()) dp[i] = 1 + dp[s.top()];
        else dp[i] = 1; 
        s.push(i);
        max_zachwytow = max(max_zachwytow, dp[i]);
    }
    cout << max_zachwytow << "\n";
    return 0;
}