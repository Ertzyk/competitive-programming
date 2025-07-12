#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n), count(101, 0), nice_nums;
    for(int &x: s) cin >> x;
    for(int i = 0; i < n; i++) count[s[i]]++;
    for(int i = 1; i <= 100; i++) if(count[i] == 1) nice_nums.push_back(i);
    if(nice_nums.size()%2 == 0){
        cout << "YES\n";
        unordered_set<int> a_nums;
        for(int i = 0; i < nice_nums.size()/2; i++) a_nums.insert(nice_nums[i]);
        for(int i = 0; i < n; i++) cout << (a_nums.count(s[i]) ? 'A' : 'B');
    } else {
        int make_nice = 0;
        for(int i = 1; i <= 100; i++) if(count[i] >= 3){
            make_nice = i;
            break;
        }
        if(make_nice == 0){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        bool made_nice = false;
        unordered_set<int> a_nums;
        for(int i = 0; i < nice_nums.size()/2; i++) a_nums.insert(nice_nums[i]);
        for(int i = 0; i < n; i++){
            if(s[i] == make_nice && !made_nice){
                made_nice = true;
                cout << 'A';
            } else cout << (a_nums.count(s[i]) ? 'A' : 'B');
        }
    }
    cout << '\n';
    return 0;
}