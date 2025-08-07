#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, result;
        cin >> n >> s;
        vector<int> bucket(26, 0);
        for(char ch: s) bucket[ch - 'a']++;
        for(int i = 0; i < 26; i++) while(bucket[i]--) result += (char)(i + 'a');
        cout << result << '\n';
    }
    return 0;
}