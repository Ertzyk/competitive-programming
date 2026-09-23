#include <iostream>
#include <bitset>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    cin >> ch;
    bitset<26> bst;
    while(ch != '}'){
        if(ch >= 'a' && ch <= 'z'){
            bst[ch - 'a'] = 1;
        }
        cin >> ch;
    }
    int res = 0;
    for(int i = 0; i < 26; i++){
        res += bst[i];
    }
    cout << res << '\n';
    return 0;
}