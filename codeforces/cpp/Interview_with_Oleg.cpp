#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 10e9 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i = 0;
    string s, result;
    cin >> n >> s;
    while(i < n){
        if(s.substr(i, 3) == "ogo"){
            i += 3;
            while(s.substr(i, 2) == "go") i += 2;
            result += "***";
        } else {
            result += s[i];
            i++;
        }
    }
    cout << result << '\n';
    return 0;
}