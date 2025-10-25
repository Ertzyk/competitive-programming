#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int lowest_conseq_A = s.size(), cur = 0, cntA = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                cur++;
                cntA++;
            } else {
                lowest_conseq_A = min(lowest_conseq_A, cur);
                cur = 0;
            }
        }
        lowest_conseq_A = min(lowest_conseq_A, cur);
        if(lowest_conseq_A == s.size()) cout << "0\n";
        else cout << cntA - lowest_conseq_A << '\n';
    }
    return 0;
}