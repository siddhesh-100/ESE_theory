#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &v, int low, int mid, int high){
    int left = low, right = mid + 1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(v[left] < v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i = low; i <= high; i++) v[i] = temp[i - low];
}

void mergeSort(vector<int> &v, int low, int high){
    if(low == high) return;
    int mid = low + (high - low)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
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
    cout << "After Sorting: ";
    mergeSort(v, 0, v.size() - 1);
    print(v);
    return 0;
}