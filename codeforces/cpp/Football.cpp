#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> scores;
    while(n--){
        string team;
        cin >> team;
        scores[team]++;
    }
    int cur_max = 0;
    string result;
    for(auto pair: scores){
        if(pair.second > cur_max) {
            result = pair.first;
            cur_max = pair.second;
        }
    }
    cout << result;
    return 0;
}