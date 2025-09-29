#include <iostream>
#include <vector>
using namespace std;

void decrease_string(string& s1, const string& s2){
    for(int i = 1; i < min(s1.size(), s2.size()); i++){
        if(s1[i] < s2[i]) return;
        else if(s1[i] > s2[i]){
            s1 = s1.substr(0, i);
            return;
        }
    }
    if(s1.size() <= s2.size()) return;
    s1 = s2;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for(string &x: a) cin >> x;
    for(int i = n - 1; i > 0; i--) decrease_string(a[i - 1], a[i]);
    for(string s: a) cout << s << '\n';
    return 0;
}