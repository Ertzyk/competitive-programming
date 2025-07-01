#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(2*k > n) cout << "Alice\n";
        else {
            int count = 0;
            for(char ch: s) if(ch == '1') count++;
            if(count <= k) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
    return 0;
}