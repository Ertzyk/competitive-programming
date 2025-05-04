#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(s[0] == '@' || s[s.size() - 1] == '@'){
        cout << "No solution";
        return 0;
    }
    vector<int> monkey_idx;
    for(int i = 1; i < s.size() - 1; i++) if(s[i] == '@') monkey_idx.push_back(i);
    if(monkey_idx.empty()){
        cout << "No solution";
        return 0;
    }
    for(int i = 0; i < monkey_idx.size() - 1; i++) if(monkey_idx[i + 1] - monkey_idx[i] <= 2){
        cout << "No solution";
        return 0;
    }
    unordered_set<int> stops;
    for(int i = 0; i < monkey_idx.size() - 1; i++) stops.insert((monkey_idx[i] + monkey_idx[i + 1])/2);
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
        if(stops.count(i)) cout << ',';
    }
    return 0;
}