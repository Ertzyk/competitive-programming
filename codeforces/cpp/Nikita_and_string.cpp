#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> a(s.size() + 1), b(s.size() + 1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            a[i + 1] = a[i] + 1;
            b[i + 1] = b[i];
        } else {
            a[i + 1] = a[i];
            b[i + 1] = b[i] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i <= s.size(); i++){
        for(int j = i; j <= s.size(); j++){
            ans = max(ans, a[i] + b[j] - b[i] + a[s.size()] - a[j]);
        }
    }
    cout << ans << '\n';
    return 0;
}