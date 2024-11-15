#include <iostream>
using namespace std;
void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minId = i;
        for(int j = i; j < n; j++){
            if(a[minId] > a[j]) minId = j;
        }
        swap(a[i], a[minId]);
    }
}
void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}