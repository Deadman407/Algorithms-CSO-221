#include <bits/stdc++.h>
#define ll long long int
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

using namespace std;

int make_equal_length(string &str1, string &str2){
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2){
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2){
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
	}
	return len1;
}

string add_binary_strings( string str1, string str2 ){
	string result;

	int length = make_equal_length(str1, str2);
	int carry = 0;

	for (int i = length-1 ; i >= 0 ; i--){
		int str1Bit = str1.at(i) - '0';
		int str2Bit = str2.at(i) - '0';

		int sum = (str1Bit ^ str2Bit ^ carry) + '0';

		result = (char)sum + result;

		carry = (str1Bit&str2Bit) | (str2Bit&carry) | (str1Bit&carry);
	}

	if (carry) result = '1' + result;

	return result;
}

int multiply_single_bit(string str1, string str2){
    return (str1[0] - '0')*(str2[0] - '0');
}

ll multiply_binary_strings(string str1, string str2){
	int n = make_equal_length(str1, str2);

	if (n == 0) return 0;
	if (n == 1) return multiply_single_bit(str1, str2);

	int left = n/2;
	int right = (n-left);

	string str1_left = str1.substr(0, left);
	string str1_right = str1.substr(left, right);

	string str2_left = str2.substr(0, left);
	string str2_right = str2.substr(left, right);

	ll prod1 = multiply_binary_strings(str1_left, str2_left);
	ll prod2 = multiply_binary_strings(str1_right, str2_right);
	ll prod3 = multiply_binary_strings(add_binary_strings(str1_left, str1_right), add_binary_strings(str2_left, str2_right));

	return prod1*(1<<(2*right)) + (prod3 - prod1 - prod2)*(1<<right) + prod2;
}

int main(){
    string str1, str2;
    cout << "Enter the first binary string : ";
    cin >> str1;
    cout << "Enter the second binary string : ";
    cin >> str2;

    ll result = multiply_binary_strings(str1, str2);
    cout << "Product of given binary strings : " << result;
}
