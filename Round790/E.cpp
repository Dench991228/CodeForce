#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;// 小于1000
    for(int current_test_case = 0; current_test_case < count_test_cases; current_test_case++ ){
        int count_candies, count_queries;
        cin >> count_candies >> count_queries;
        int *arr = (int *)malloc(sizeof(int)*count_candies);
        int prefix_sum = 0;
        for(int i = 0; i < count_candies; i++){// 接收输入数组
            cin >> arr[i];
        }
        sort(arr, arr+count_candies, greater<int>());
        for(int i = 0; i < count_candies; i++){// 计算前缀和
            prefix_sum += arr[i];
            arr[i] = prefix_sum;
        }
        for(int i = 0; i < count_queries; i++){
            int q;
            cin >> q;
            int * result = lower_bound(arr, arr+count_candies, q);
            if(result - arr >= count_candies){
                cout << "-1" << endl;
            }else{
                cout << result - arr + 1 << endl;
            }
        }
    }
    return 0;
}