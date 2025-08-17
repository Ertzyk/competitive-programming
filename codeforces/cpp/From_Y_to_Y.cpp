#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    if(k == 0){
        cout << "a\n";
        return 0;
    }
    vector<int> count_letters;
    while(k){
        int l = 2, r = 447, ans = 2;
        while(l <= r){
            int m = (l + r)/2;
            if(m*(m - 1)/2 <= k){
                ans = m;
                l = m + 1;
            } else r = m - 1;
        }
        k -= ans*(ans - 1)/2;
        count_letters.push_back(ans);
    }
    string result;
    for(int i = 0; i < count_letters.size(); i++) for(int j = 0; j < count_letters[i]; j++) result += (char)('a' + i);
    cout << result << '\n';
    return 0;
}