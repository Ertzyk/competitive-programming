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
        for(int i = 0; i < k; i++) s += '1';
        for(int i = k; i < n; i++) s += '0';
        cout << s << '\n';
    }
    return 0;
}