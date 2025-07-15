#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, count_ones = 0;
        cin >> n;
        bool odd_size = false;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(char ch: s) if(ch == '1') count_ones++;
            if(s.size()%2 == 1) odd_size = true;
        }
        if(odd_size || count_ones%2 == 0) cout << n << '\n';
        else cout << n - 1 << '\n';
    }
    return 0;
}