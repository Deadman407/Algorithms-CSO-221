#include <bits/stdc++.h>
#define ll long long int
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];

  int i = (low - 1);

  for(int j = low; j < high; j++){
    if(arr[j] <= pivot){

      i++;

      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return (i + 1);
}

void quick_sort(int arr[], int low, int high){
    int stack[high - low + 1];

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0){
        high = stack[top--];
        low = stack[top--];

        int p = partition(arr, low, high);

        if(p - 1 > low){
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if(p + 1 < high){
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){
    int n;
    cout << "Enter the size of array to be sorted : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array of size " << n << ":  ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    cout << "Sorted array in Ascending order : ";
    printArr(arr, n);
    return 0;
}
