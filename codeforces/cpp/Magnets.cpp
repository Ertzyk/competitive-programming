#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    string prev = "x";
    while(n--){
        string s;
        cin >> s;
        if(s != prev){
            result++;
            prev = s;
        }
    }
    cout << result << '\n';
    return 0;
}