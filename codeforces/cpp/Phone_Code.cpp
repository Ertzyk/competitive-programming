#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string longest_prefix;
    cin >> n >> longest_prefix;
    n--;
    while(n--){
        string s;
        cin >> s;
        for(int i = 0; i < longest_prefix.size(); i++){
            if(longest_prefix[i] != s[i]){
                longest_prefix = longest_prefix.substr(0, i);
                break;
            }
        }
    }
    cout << longest_prefix.size() << '\n';
    return 0;
}