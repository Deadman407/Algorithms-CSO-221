

#include<bits/stdc++.h>
using namespace std;

#define int_pair pair<int, int>

set<int_pair> hull;

int find_side(int_pair p1, int_pair p2, int_pair p){
	int val = (p.second - p1.second) * (p2.first - p1.first) -
			(p2.second - p1.second) * (p.first - p1.first);

	if (val >= 0)
		return 1;
	if (val < 0)
		return -1;
	return 0;
}

int line_dist(int_pair p1, int_pair p2, int_pair p){
	return abs((p.second - p1.second) * (p2.first - p1.first) -
			(p2.second - p1.second) * (p.first - p1.first));
}

void quick_hull(int_pair a[], int n, int_pair p1, int_pair p2, int side){
	int ind = -1;
	int max_dist = 0;

	for(int i=0; i<n; i++){
		int temp = line_dist(p1, p2, a[i]);
		if (find_side(p1, p2, a[i]) == side && temp >= max_dist){
			ind = i;
			max_dist = temp;
		}
	}

	if (ind == -1){
		hull.insert(p1);
		hull.insert(p2);
		return;
	}

	quick_hull(a, n, a[ind], p1, -find_side(a[ind], p1, p2));
	quick_hull(a, n, a[ind], p2, -find_side(a[ind], p2, p1));
}

void print_hull(int_pair a[], int n){
	if (n < 3){
		cout << "Convex hull not possible\n";
		return;
	}

	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++){
		if (a[i].first < a[min_x].first)
			min_x = i;
		if (a[i].first > a[max_x].first)
			max_x = i;
	}

	quick_hull(a, n, a[min_x], a[max_x], 1);

	quick_hull(a, n, a[min_x], a[max_x], -1);

	cout << "The points in Convex Hull are:\n";
	while (!hull.empty())
	{
		cout << "(" <<( *hull.begin()).first << ", "
			<< (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
}

int main(){
	int_pair a[] = {{0, 3}, {1, 2}, {3, 1}, {1, 1}, {4, 4}};
	int n = sizeof(a)/sizeof(a[0]);
	print_hull(a, n);
	return 0;
}
