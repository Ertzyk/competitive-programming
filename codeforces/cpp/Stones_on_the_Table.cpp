#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i < n; i++) if(s[i - 1] == s[i]) result++;
    cout << result;
    return 0;
}