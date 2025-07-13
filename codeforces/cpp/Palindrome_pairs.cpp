#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<ll> start_pos(s.size()), end_pos(s.size()), sum_start_pos(s.size());
    for(int i = 0; i < s.size(); i++){
        start_pos[i]++;
        end_pos[i]++;
        for(int d = 1; i - d >= 0 && i + d < s.size(); d++){
            if(s[i - d] == s[i + d]){
                start_pos[i - d]++;
                end_pos[i + d]++;
            } else break;
        }
    }
    for(int i = 0; i < s.size() - 1; i++){
        for(int d = 0; i - d >= 0 && i + d + 1 < s.size(); d++){
            if(s[i - d] == s[i + d + 1]){
                start_pos[i - d]++;
                end_pos[i + d + 1]++;
            } else break;
        }
    }
    ll cur_sum = 0, result = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        cur_sum += start_pos[i];
        sum_start_pos[i] = cur_sum;
    }
    for(int i = 0; i < s.size() - 1; i++) result += end_pos[i]*sum_start_pos[i + 1];
    cout << result << '\n';
    return 0;
}