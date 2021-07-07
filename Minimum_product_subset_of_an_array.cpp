#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int product(int n, vector<int> &arr)
{
	if (n == 1)
		return arr[0];

	int product = 1;
	int mn = INT_MIN;
	int min_pos = INT_MAX;
	int c_neg = 0, c_zero = 0;
	for (auto val : arr)
	{
		if (val == 0)
			c_zero++;

		if (val < 0)
		{
			c_neg++;
			mn = max(mn, val);
		}
		if (val > 0)
		{
			min_pos = min(min_pos, val);
		}
		product *= val;
	}
	// Here is the crux of the problem here we will have to return the result as per the need.
	// condition 1 -> all the numbers are zero or all are non negative but contains zero
	if (c_zero == n or (c_neg == 0 and c_zero > 1))
	{
		return 0;
	}

	if (c_neg == 0)
	{
		return min_pos;
	}
	if (!(c_neg & 1) and c_neg != 0)
	{
		product /= mn; // here mn is the max negative
	}

	return product;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr)
		cin >> x;
	cout << product(n, arr) << endl;
	return 0;
}