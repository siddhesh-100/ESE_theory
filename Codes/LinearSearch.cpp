#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    int target; cin >> target;
    bool found = false;
    int id;
    for(int i = 0; i < n; i++){
        if(v[i] == target){
            found = true;
            id = i;
            break;
        }
    }
    if(found) cout << target << " found at index " << id << "\n";
    else cout << target << " is not present in the array\n";
    return 0; 
}