#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}
int search(vector<int> &v, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(target == v[mid]) return mid;
    else if(target > v[mid]) return search(v, mid + 1, high, target);
    else if(target < v[mid]) return search(v, low, mid - 1, target);
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    int target; cin >> target;
    // sort(v);
    cout << search(v, 0, v.size() - 1, target) << endl;
    return 0;
}