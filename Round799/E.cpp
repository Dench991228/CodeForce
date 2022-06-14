#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    // 滑动窗口
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length, expected_sum;
        cin >> length >> expected_sum;
        int arr[length];
        int min_index_prefix[length+1];// 具有某个前缀和的最小下标
        int max_index_prefix[length+1];// 具有某个前缀和的最大下标
        int prefix_sum = 0;
        for(int i = 0; i < length+1; i++){
            min_index_prefix[i] = 0x7fffffff;
            max_index_prefix[i] = 0;
        }
        min_index_prefix[0] = -1;
        for(int i = 0; i < length; i++){
            cin >> arr[i];
            prefix_sum += arr[i];
            min_index_prefix[prefix_sum] = min(min_index_prefix[prefix_sum], i);
            max_index_prefix[prefix_sum] = max(max_index_prefix[prefix_sum], i);
        }
        if(prefix_sum < expected_sum){// 如果达不到，就扔掉
            cout << -1 << endl;
            continue;
        }else{
            int max_window = 0;
            for(int current_sum = expected_sum; current_sum <= prefix_sum; current_sum ++){
                max_window = max(max_window, max_index_prefix[current_sum] - min_index_prefix[current_sum - expected_sum]);
                //cout << current_sum << " " << max_index_prefix[current_sum] << " " << current_sum - expected_sum << " " <<min_index_prefix[current_sum - expected_sum]<< endl;
            }
            cout << length - max_window << endl;
        }
    }
    return 0;
}