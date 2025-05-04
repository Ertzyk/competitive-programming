#include <iostream>
#include <vector>
using namespace std;

bool empty_prim(vector<int> a){
    if(a[1] > 0 && a[2] > 0 && a[3]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> count(4);
        int l = 0, result = 200001;
        for(int r = 0; r < s.size(); r++){
            count[s[r] - '0']++;
            while(!empty_prim(count)){
                result = min(result, r - l + 1);
                count[s[l] - '0']--;
                l++;
            }
        }
        cout << ((result == 200001) ? 0 : result) << '\n';
    }
    return 0;
}