#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case++){
        int length, k;
        cin >> length >> k;
        // 先对a数组进行一个从小到大排序
        int arr[length];
        for(int i = 0; i < length; i++){
            cin >> arr[i];
        }
        sort(arr, arr+length);
        // 然后对a数组进行一个压缩，记录压缩过的新数以及频率
        int last_distinct = -1;
        int count_distinct = 0;// 之前已有多少个不同的元素
        int frequent[length];// 各个table中下标对应的元素的出现频次
        int table[length];
        for(int i = 0; i < length; i ++){
            frequent[i] = 0;
        }
        for(int i = 0; i < length; i ++){
            if(arr[i] != last_distinct){
                table[count_distinct] = arr[i];
                last_distinct = arr[i];
                count_distinct ++;
            }
            frequent[count_distinct-1] ++;
        }
        frequent[count_distinct] =0;
        count_distinct ++;
        // 使用栈存储frequent，以及其下标
        vector<int> subscript = vector<int>();
        int total_frequent = 0;
        int max_frequent = 0;
        int left_subscript = -1, right_subscript = -1;
        for(int i = 0; i < count_distinct; i++){
            if(frequent[i] >= k && (table[i] == subscript[subscript.size()-1]+1)){// 入栈即可
                subscript.push_back(i);
                total_frequent += frequent[i];
            }else{// 出栈
                if(total_frequent > max_frequent){
                    max_frequent = total_frequent;
                    left_subscript = subscript[0];
                    right_subscript = subscript[subscript.size()-1];
                    total_frequent = 0;
                }
                subscript.clear();
            }
        }
        if(left_subscript != -1){
            cout << table[left_subscript] << " " << table[right_subscript] << endl;
        }else{
            cout << "-1" << endl;
        }
    }
    return 0;
}