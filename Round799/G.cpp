#include <iostream>

using namespace std;

// 不断地找最大的符合条件的序列
int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length, expected_length;
        cin >> length >> expected_length;
        expected_length ++;
        int arr[length];
        for(int i = 0; i < length; i++){
            cin >> arr[i];
        }
        int left_ptr = 0, right_ptr = 1;
        int found = 0;
        while(right_ptr < length){
            int cur_length = 0;
            while(right_ptr < length && arr[right_ptr] * 2 > arr[right_ptr-1]){
                right_ptr ++;
            }
            // right_ptr指向的元素不属于上述子数组或者超过了边界
            cur_length = right_ptr - left_ptr;
            //cout << right_ptr << " " << left_ptr<< endl;
            if(cur_length >= expected_length)found += (cur_length - expected_length + 1);
            left_ptr = right_ptr;
            right_ptr ++;
        }
        cout << found << endl;
    }
    return 0;
}