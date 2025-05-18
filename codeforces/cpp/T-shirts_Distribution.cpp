#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int size_to_int(string s){
    if(s == "S") return 0;
    else if(s == "M") return 1;
    else if(s == "L") return 2;
    else if(s == "XL") return 3;
    else if(s == "XXL") return 4;
    else return 5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> sizes(6);
    for(int &x: sizes) cin >> x;
    int n;
    cin >> n;
    vector<string> result(n);
    vector<pair<int, pair<string, string>>> undecided;
    for(int i = 0; i < n; i++){
        string s, curr = "";
        cin >> s;
        vector<string> person;
        for(char ch: s){
            if(ch == ','){
                person.push_back(curr);
                curr = "";
            } else curr += ch;
        }
        person.push_back(curr);
        if(person.size() == 1){
            if(sizes[size_to_int(person[0])] == 0){
                for(int j = i + 1; j < n; j++){
                    string x;
                    cin >> x;
                }
                cout << "NO\n";
                return 0;
            }
            result[i] = person[0];
            sizes[size_to_int(person[0])]--;
        } else undecided.push_back({i, {person[0], person[1]}});
    }
    sort(undecided.begin(), undecided.end(), [](pair<int, pair<string, string>> a, pair<int, pair<string, string>> b){
        return size_to_int(a.second.first) < size_to_int(b.second.first);
    });
    for(auto p: undecided){
        if(sizes[size_to_int(p.second.first)] > 0){
            sizes[size_to_int(p.second.first)]--;
            result[p.first] = p.second.first;
        } else {
            if(sizes[size_to_int(p.second.second)] > 0){
                sizes[size_to_int(p.second.second)]--;
                result[p.first] = p.second.second;
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(string s: result) cout << s << '\n';
    return 0;
}