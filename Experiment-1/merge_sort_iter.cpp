#include <bits/stdc++.h>
#define ll long long int
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

using namespace std;

void merge_sort(int arr[],int n);

void merge_pass(int arr[],int temp[],int size,int n);

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);

void copy(int arr[],int temp[],int n);

void printArr(int arr[], int n);

int main(){
    int n;
    cout << "Enter the size of array to be sorted : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array of size " << n << ":  ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, n);
    cout << "Sorted array in Ascending order : ";
    printArr(arr, n);
    return 0;
}

void merge_sort(int arr[],int n)
{
	int temp[n];
	int size=1;
	while(size<n)
	{
		merge_pass(arr,temp,size,n);
		size=size*2;
	}
}

void merge_pass(int arr[],int temp[],int size,int n){
	int i,low1,up1,low2,up2;
	low1=0;
	while(low1+size<n)
	{
		up1=low1+size-1;
		low2=low1+size;
		up2=low2+size-1;
		if(up2>=n)
		up2=n-1;
		merge(arr,temp,low1,up1,low2,up2);
		low1=up2+1;
	}

	for(i=low1;i<=n-1;i++)
	temp[i]=arr[i];

	copy(arr,temp,n);
}

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2){
	int i=low1,j=low2,k=low1;
	while(i<=up1 && j<=up2)
	{
		if(arr[i]<arr[j])
		temp[k++]=arr[i++];
		else
		temp[k++]=arr[j++];
	}
	while(i<=up1)
		temp[k++]=arr[i++];
	while(j<=up2)
		temp[k++]=arr[j++];
}

void copy(int arr[],int temp[],int n){
	int i;
	for(i=0;i<n;i++)
	arr[i]=temp[i];
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
