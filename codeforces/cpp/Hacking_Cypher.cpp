#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int a, b;
    cin >> s >> a >> b;
    vector<bool> prefix_a(s.size() + 1, false), postfix_b(s.size() + 1, false);
    int p = 0, power_of_10 = 1;
    for(int i = 1; i <= s.size(); i++){
        p = (p*10 + (s[i - 1] - '0'))%a;
        if(p == 0) prefix_a[i] = true;
    }
    p = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        p = (power_of_10*(s[i] - '0') + p)%b;
        if(p == 0 && s[i] != '0') postfix_b[i] = true;
        power_of_10 = power_of_10*10%b;
    }
    for(int i = 1; i <= s.size(); i++) if(prefix_a[i] && postfix_b[i]){
        cout << "YES\n" << s.substr(0, i) << '\n' << s.substr(i, s.size()) << '\n';
        return 0;
    }
    cout << "NO\n";
    return 0;
}