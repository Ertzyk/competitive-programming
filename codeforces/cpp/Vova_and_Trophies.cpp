#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> gold_seg_len, idx_with_one_apart;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G') cur++;
        else if(s[i] == 'S' && cur){
            if(i < n - 1 && s[i + 1] == 'G') idx_with_one_apart.push_back(gold_seg_len.size());
            gold_seg_len.push_back(cur);
            cur = 0;
        }
    }
    if(cur) gold_seg_len.push_back(cur);
    if(gold_seg_len.size() == 0) cout << "0\n";
    else if(gold_seg_len.size() == 1) cout << gold_seg_len[0] << '\n';
    else if(gold_seg_len.size() == 2){
        if(idx_with_one_apart.size()) cout << gold_seg_len[0] + gold_seg_len[1] << '\n';
        else cout << max(gold_seg_len[0], gold_seg_len[1]) + 1 << '\n';
    } else {
        int ans = 0;
        for(int i = 0; i < gold_seg_len.size(); i++) ans = max(ans, gold_seg_len[i] + 1);
        for(int i = 0; i < idx_with_one_apart.size(); i++) ans = max(ans, gold_seg_len[idx_with_one_apart[i]] + gold_seg_len[idx_with_one_apart[i] + 1] + 1);
        cout << ans << '\n';
    }
    return 0;
}