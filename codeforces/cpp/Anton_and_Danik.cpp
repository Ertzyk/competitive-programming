#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) if(s[i] == 'A') count++;
    cout << ((2*count > n) ? "Anton\n" : ((2*count == n) ? "Friendship\n" : "Danik\n"));
    return 0;
}