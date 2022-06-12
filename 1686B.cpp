#include <iostream>

using namespace std;

int main(){
	int count_cases;
	cin >> count_cases;
	for(int current_case = 0; current_case < count_cases; current_case ++){
		int length_permutation;
		cin >> length_permutation;
		int dp[length_permutation];// 从最初到这里最多可以完成几次odd划分
		// dp[i] = max(dp[i-1], dp[i-2]+(arr[i-1]>arr[i]))
		int *arr = (int*)malloc(sizeof(int) * length_permutation);
		for(int i = 0; i < length_permutation; i++){
			cin >> arr[i];
		}
		dp[0] = 0;
		dp[1] = arr[0]>arr[1]?1:0;
		for(int i = 2; i < length_permutation;i++){
			dp[i] = max(dp[i-1], dp[i-2] + (arr[i-1] > arr[i] ? 1:0));
		}
		cout << dp[length_permutation-1] << endl;
	}
  	return 0;
}