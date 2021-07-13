#include<bits/stdc++.h>
using namespace std;
int fun(int n,int k , int arr[]){
        if(n==1)
					return arr[0];
				int mn_val = *min_element(arr, arr + n);
				int sum = 0;
				for (int i = 0; i < n;i++){
					if(sum!=mn_val)
					sum += arr[i];
				}
					if ((mn_val > 0 and !(k & 1)) or (mn_val < 0 and (k & 1)))
					{
						sum = sum - mn_val;
					}
				return sum;
}

int main(){
	int n,k;
	cin >> n>>k;
	int arr[n];
	for(auto &x:arr){
		cin >> x;
	}
	cout << fun(n,k, arr) << "\n";
	return 0;
}


//Hello somil verma sir 