#include <iostream>
#include <vector>
using namespace std;

int solve(int l, int r, const string& s, char ch, const vector<vector<int>>& prefix_letters){
    if(l == r) return ((s[l] == ch) ? 0 : 1);
    int option1_rec = solve(l, (l + r)/2, s, (char)(ch + 1), prefix_letters);
    int option1_cnt_ch = (r - l + 1)/2 - prefix_letters[ch - 'a'][r + 1] + prefix_letters[ch - 'a'][(l + r)/2 + 1];
    int option2_rec = solve((l + r)/2 + 1, r, s, (char)(ch + 1), prefix_letters);
    int option2_cnt_ch = (r - l + 1)/2 - prefix_letters[ch - 'a'][(l + r)/2 + 1] + prefix_letters[ch - 'a'][l];
    return min(option1_rec + option1_cnt_ch, option2_rec + option2_cnt_ch);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> prefix_letters(26, vector<int>(n + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++) prefix_letters[j][i] = prefix_letters[j][i - 1];
            prefix_letters[s[i - 1] - 'a'][i]++;
        }
        cout << solve(0, n - 1, s, 'a', prefix_letters) << '\n';
    }
}