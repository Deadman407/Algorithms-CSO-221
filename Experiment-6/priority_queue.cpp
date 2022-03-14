#include <bits/stdc++.h>
using namespace std;

int H[50];
int size = -1;

int parent(int i){
	return (i - 1) / 2;
}

int left_child(int i){
	return ((2 * i) + 1);
}

int right_child(int i){
	return ((2 * i) + 2);
}

void shift_up(int i){
	while (i > 0 && H[parent(i)] < H[i]){
		swap(H[parent(i)], H[i]);

		i = parent(i);
	}
}

void shift_down(int i){
	int max_index = i;

	int l = left_child(i);

	if (l <= size && H[l] > H[max_index]){
		max_index = l;
	}

	int r = right_child(i);

	if (r <= size && H[r] > H[max_index]){
		max_index = r;
	}

	if (i != max_index){
		swap(H[i], H[max_index]);
		shift_down(max_index);
	}
}

void insert(int p){
	size = size + 1;
	H[size] = p;

	shift_up(size);
}

int extract_max(){
	int result = H[0];

	H[0] = H[size];
	size = size - 1;

	shift_down(0);
	return result;
}

int get_max(){
	return H[0];
}

void remove(int i){
	H[i] = get_max() + 1;

	shift_up(i);

	extract_max();
}

int main(){
	insert(76);
	insert(7);
	insert(49);
	insert(28);
	insert(45);
	insert(4);
	insert(23);

	int i = 0;

	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	cout << "Node with maximum priority : "
		<< extract_max() << "\n";

	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= size) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";

	remove(2);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= size) {
		cout << H[l] << " ";
		l++;
	}
	return 0;
}
