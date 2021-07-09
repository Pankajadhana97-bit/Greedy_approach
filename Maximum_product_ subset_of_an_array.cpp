#include <bits/stdc++.h>
using namespace std;
int fun(int n, vector<int> &arr)
{
	if (n == 1)
	{ //it is in that case where we only one element
		return arr[0];
	}

	int product = 1;			// initialize the product
	int zero_count = 0;		//count the number of the zeroes in the vector
	int mx_neg = INT_MIN; // finding the max negative for the case like we have only odd negatives in the vector
	vector<int> negs;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			zero_count++;

		if (arr[i] < 0)
		{
			product *= arr[i];
			mx_neg = max(mx_neg, arr[i]);
		}

		if (arr[i] > 0)
		{
			product *= arr[i];
		}
	}
	if (zero_count == n)
	{
		return 0;
	}
	if (negs.size() > 0 and !(negs.size() & 1))
	{
		// no change
		return product;
	}
	else
	{
		return product / mx_neg;
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
	cout << fun(n, arr) << endl;
	return 0;
}