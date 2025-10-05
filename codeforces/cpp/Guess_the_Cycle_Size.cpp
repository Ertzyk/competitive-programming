#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(ll i = 2; i <= 26; i++){
        cout << "? 1 " << i << '\n';
        cout.flush();
        ll responce, responce2;
        cin >> responce;
        if(responce == -1){
            cout << "! " << i - 1 << '\n';
            return 0;
        }
        cout << "? " << i << " 1\n";
        cout.flush();
        cin >> responce2;
        if(responce != responce2){
            cout << "! " << responce + responce2 << '\n';
            return 0;
        }
    }
    cout << "! 27\n";
    return 0;
}