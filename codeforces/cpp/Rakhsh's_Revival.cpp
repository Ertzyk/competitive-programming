#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, conseq0 = 0, result = 0;
        string s;
        cin >> n >> m >> k >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') conseq0++;
            else conseq0 = 0;
            if(conseq0 == m){
                conseq0 = 0;
                result ++;
                i += k - 1;
            }
        }
        cout << result << '\n';
    }
    return 0;
}