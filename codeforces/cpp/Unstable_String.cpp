#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll l = 0, r = 0;
        ll result = 0;
        while(r < s.size()){
            while(r < s.size() && (s[r] - '0' == r%2 || s[r] == '?')) r++;
            result += (r - l + 1)*(r - l)/2;
            r++;
            l = r;
        }
        l = 0;
        r = 0;
        while(r < s.size()){
            while(r < s.size() && (s[r] - '0' == (r + 1)%2 || s[r] == '?')) r++;
            result += (r - l + 1)*(r - l)/2;
            r++;
            l = r;
        }
        l = 0;
        r = 0;
        while(r < s.size()){
            while(r < s.size() && s[r] == '?') r++;
            result -= (r - l + 1)*(r - l)/2;
            r++;
            l = r;
        }
        cout << result << '\n';
    }
    return 0;
}