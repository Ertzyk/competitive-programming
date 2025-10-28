#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        bool out = false;
        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0){
                cout << "NO\n";
                out = true;
                break;
            }
        }
        if(!out) cout << "YES\n";
    }
    return 0;
}