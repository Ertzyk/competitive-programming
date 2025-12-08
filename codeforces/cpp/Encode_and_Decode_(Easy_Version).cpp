#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    cin >> t;
    if(t == "first"){
        int n;
        cin >> n;
        string res;
        while(n--){
            int a;
            cin >> a;
            res += (char)('a' + a - 1);
        }
        cout << res << '\n';
    } else {
        string s;
        cin >> s;
        cout << s.size() << '\n';
        for(char ch: s) cout << ch - 'a' + 1 << ' ';
        cout << '\n';
    }
    return 0;
}