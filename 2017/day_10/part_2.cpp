#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a, shift, xr;
	string s = "130,126,1,11,140,2,255,207,18,254,246,164,29,104,0,224";
	for (int i = 0; i < 256; i++)
		a.push_back(i);

	for (auto i : s)
		shift.push_back(int(i));

	shift.insert(shift.end(), {17, 31, 73, 47, 23});

	int skip = 0, rev = 0;

	for (int k = 0; k < 64; k++){
		for (auto i : shift){
			reverse(a.begin(), a.begin() + i);
			rotate(a.begin(), a.begin() + (i + (skip++)) % 256, a.end());
			rev += i + skip - 1;
		}
	}

	rotate(a.rbegin(), a.rbegin() + (rev) % 256, a.rend());

	for (int i = 0; i < 256; i += 16)
		xr.push_back(accumulate(a.begin() + i, a.begin() + i + 16, 0, bit_xor<int>()));

	for (auto i : xr)
		cout << setfill('0') << setw(2) << hex << i;
}
