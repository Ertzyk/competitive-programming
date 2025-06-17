#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool answer = false;
        unordered_set<int> sett;
        for(int i = 0; i < n - 1; i++){
            if(sett.count(s[i] - 'a')){
                cout << "Yes\n";
                answer = true;
                break;
            } else sett.insert(s[i] - 'a');
        }
        sett.clear();
        if(!answer){
            for(int i = 1; i < n; i++){
                if(sett.count(s[i] - 'a')){
                    cout << "Yes\n";
                    answer = true;
                    break;
                } else sett.insert(s[i] - 'a');
            }
        }
        if(!answer) cout << "No\n";
    }
    return 0;
}