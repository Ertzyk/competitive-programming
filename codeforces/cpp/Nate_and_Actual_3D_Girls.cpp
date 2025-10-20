#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(char ch : s) cnt[(ch - 'a' - k + 26*4)%26]++;
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(char ch : s) cnt[ch - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(cnt[i] < 0){
            cout << "It is gonna be daijoubu.\n";
            return 0;
        }
    }
    cout << "Make her kokoro go doki-doki!\n";
    return 0;
}