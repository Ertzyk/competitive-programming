#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map<int, int> count;
        for(char ch: s) count[ch - '0']++;
        string result = "";
        for(int i = 9; i >= 0; i--){
            int k = i;
            while(count[k] == 0) k++;
            result += (char)(k + '0');
            count[k]--;
        }
        cout << result << '\n';
    }
    return 0;
}