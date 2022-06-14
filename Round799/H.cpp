#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        int chart[length];// 对照表
        int count_distinct;// 当前不同的数
        int firstAppear[length];// 第一次出现表
        int lastAppear[length];// 最后一次出现表
        int frequency[length];// 频率
        for(int i = 0; i < length; i++){
            chart[i] = -1;
            firstAppear[i] = 0;
            lastAppear[i] = 0;
        }
        for(int i = 0; i < length; i++){
            int number;
            cin >> number;
            if(chart[number] == -1){
                chart[count_distinct] = number;
                count_distinct ++;
                firstAppear[chart[number]] = i;
            }
            frequency[chart[number]] ++;
            lastAppear[chart[number]] = max(lastAppear[chart[number]], i);
        }
        int result = 0x80000000;
        int left = -1, right = -1, value = -1; 
        for(int i = 0; i < count_distinct; i++){
            result = max(result, frequency[i] - lastAppear[i] - firstAppear[i]);
        }
        cout << chart
    }
    return 0;
}