#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int l = 1, r = s.size()/2 + 1, k = r;
    while(l <= r){
        int m = (l + r)/2;
        vector<bool> valid(26, false);
        vector<int> freq(26, 0);
        for(int i = 0; i < m; i++){
            freq[s[i] - 'a']++;
            valid[s[i] - 'a'] = true;
        }
        for(int i = m; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[s[i - m] - 'a']--;
            if(freq[s[i - m] - 'a'] == 0) valid[s[i - m] - 'a'] = false;
        }
        bool valid_k = false;
        for(auto b: valid) if(b) valid_k = true;
        if(valid_k){
            k = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << k << '\n';
    return 0;
}