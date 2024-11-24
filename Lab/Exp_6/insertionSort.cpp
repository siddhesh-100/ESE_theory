#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &v){
    for(int i = 0; i <  v.size(); i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}
void print(vector<int> &v){
    for(const auto &i : v) cout << i << " ";
    cout << "\n";
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    cout << "Before Sorting: ";
    print(v);
    insertionSort(v);
    cout << "After sorting: ";
    print(v);
    return 0;       
}