#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map<int, ll> prefix_sums;
        prefix_sums[0] = 1;
        int cur = 0;
        ll result = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') cur--;
            else cur++;
            result += prefix_sums[cur]*(s.size() - i);
            result %= MOD;
            prefix_sums[cur] += i + 2;
        }
        cout << result << '\n';
    }
    return 0;
}