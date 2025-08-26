#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, s, ans;
    cin >> a >> b >> s;
    unordered_map<char, char> mp;
    for(int i = 0; i < a.size(); i++){
        mp[a[i]] = b[i];
        mp[(char)(a[i] - 'a' + 'A')] = (char)(b[i] - 'a' + 'A');
    }
    for(int i = 0; i < s.size(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ans += mp[s[i]];
        else ans += s[i];
    }
    cout << ans << '\n';
    return 0;
}