#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll v1 = 0, o = 0, v2 = 0, cur = 1;
    char prev = s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] != prev){
            if(prev == 'v'){
                v1 += cur - 1;
                v2 += (cur - 1)*o;
            } else o += v1*cur;
            cur = 1;
            prev = s[i];
        } else cur++;
    }
    if(prev == 'v') v2 += (cur - 1)*o;
    cout << v2;
    return 0;
}