#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    vector<int> a(n), left_0(n + 1, 0), right_1(n + 1, 0);
    for(int &x: a) cin >> x;
    for(int i = 0; i < n; i++) left_0[i + 1] = left_0[i] + ((a[i] == 0) ? 1 : 0);
    for(int i = n - 1; i >= 0; i--) right_1[i] = right_1[i + 1] + ((a[i] == 1) ? 1 : 0);
    for(int i = 0; i <= n; i++) result = max(result, left_0[i] + right_1[i]);
    cout << result << '\n';
    return 0;
}