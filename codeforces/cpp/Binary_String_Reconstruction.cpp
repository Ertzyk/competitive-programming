#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        int x;
        cin >> s >> x;
        string w(s.size(), '1');
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                if(i + x < s.size()) w[i + x] = '0';
                if(i - x >= 0) w[i - x] = '0';
            }
        }
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1' && (i + x >= s.size() || w[i + x] == '0') && (i - x < 0 || w[i - x] == '0')){
                cout << "-1\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << w << '\n';
    }
    return 0;
}