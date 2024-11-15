#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
void bubbleSort(vi &v){
    int n = v.size();
    for(int i = n - 1; i > -1; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}
void selectionSort(vi &v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        int minId = i;
        for(int j = i; j < n; j++){
            if(v[j] < v[minId]) minId = j;
        }
        swap(v[i], v[minId]);
    }
}
void insertionSort(vi &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        } 
    }
}
void print(vi &v){
    for(const auto &i : v) cout << i << " ";
    cout << endl;
}
int binarySearch(vi &v, int target){
    int i = 0, j = v.size() - 1;
    while(i <= j){
        int m = i + (j - i)/2;
        if(target == v[m]) return m;
        if(target > v[m]) i = m + 1;
        if(target < v[m]) j = m - 1;
    }
    return -1;
}
int recursiveBinarySearch(vi &v, int target, int i, int j){
    if(i > j) return -1;
    int m = i + (j - i)/2;
    if(v[m] == target) return m;
    if(target > v[m]) return recursiveBinarySearch(v, target, m + 1, j);
    if(target < v[m]) return recursiveBinarySearch(v, target, i, m - 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;
    print(v);
    insertionSort(v);
    print(v);
    cout << recursiveBinarySearch(v, 1 , 0, v.size() - 1);
    return 0;
}