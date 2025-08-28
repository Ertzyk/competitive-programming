#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string good_str, pattern;
    int n, star_idx = -1;
    cin >> good_str >> pattern >> n;
    vector<bool> good(26);
    for(char ch: good_str) good[ch - 'a'] = true;
    for(int i = 0; i < pattern.size(); i++) if(pattern[i] == '*'){
        star_idx = i;
        break;
    }
    while(n--){
        string s;
        cin >> s;
        if(star_idx == -1){
            if(s.size() != pattern.size()){
                cout << "NO\n";
                continue;
            }
            bool ok = true;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != pattern[i] && (pattern[i] != '?' || !good[s[i] - 'a'])){
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            if(s.size() < pattern.size() - 1){
                cout << "NO\n";
                continue;
            }
            bool ok = true;
            for(int i = 0; i < star_idx; i++) if(s[i] != pattern[i] && (pattern[i] != '?' || !good[s[i] - 'a'])){
                ok = false;
                break;
            }
            if(!ok){
                cout << "NO\n";
                continue;
            }
            for(int i = star_idx + 1; i < pattern.size(); i++) if(s[(int)s.size() + i - (int)pattern.size()] != pattern[i] && (pattern[i] != '?' || !good[s[(int)s.size() + i - (int)pattern.size()] - 'a'])){
                ok = false;
                break;
            }
            if(!ok){
                cout << "NO\n";
                continue;
            }
            for(int i = star_idx; i <= (int)s.size() + star_idx - (int)pattern.size(); i++) if(good[s[i] - 'a']){
                ok = false;
                break;
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}