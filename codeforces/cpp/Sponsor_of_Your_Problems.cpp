#include <iostream>
#include <string>
using namespace std;

int solve(string a, string b){
    if(a.size() == 0) return 0;
    if((b[0] - '0') - (a[0] - '0') >= 2) return 0;
    if((b[0] - '0') - (a[0] - '0') == 1){
        int result = 1, i = 1;
        while(i < a.size() && a[i] == '9' && b[i] == '0'){
            result++;
            i++;
        }
        return result;
    }
    return 2 + solve(a.substr(1, a.size() - 1), b.substr(1, b.size() - 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
    return 0;
}