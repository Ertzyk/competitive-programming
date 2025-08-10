#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()){
        cout << "NO\n";
        return 0;
    }
    bool a_one_one = false, b_one_one = false;
    for(char ch: a) if(ch == '1'){
        a_one_one = true;
        break;
    }
    for(char ch: b) if(ch == '1'){
        b_one_one = true;
        break;
    }
    if(a_one_one^b_one_one) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}