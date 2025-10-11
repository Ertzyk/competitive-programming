#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, zeros = 0, ones = 0, twos = 0;
        string s, result;
        cin >> n >> k >> s;
        if(n == k){
            string result2(n, '-');
            cout << result2 << '\n';
            continue;
        }
        for(int i = 0; i < n; i++) result += '+';
        for(char ch: s){
            if(ch == '0') zeros++;
            else if(ch == '1') ones++;
            else twos++;
        }
        for(int i = 0; i < zeros; i++) result[i] = '-';
        for(int i = 0; i < ones; i++) result[n - i - 1] = '-';
        for(int i = zeros; i < zeros + twos; i++) result[i] = '?';
        for(int i = n - (ones - 1) - 2; i > n - (ones - 1) - 2 - twos; i--) result[i] = '?';
        cout << result << '\n';
    }
    return 0;
}