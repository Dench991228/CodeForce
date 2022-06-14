#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        int arr[10001];
        for(int i = 0; i <= 10000; i++){
            arr[i] = 0;
        }
        int result = 0;
        for(int i = 0; i < length; i++){
            int number;
            cin >> number;
            arr[number]++;
            if(arr[number] >=2){
                result ++;
            }
        }
        if(result % 2 == 0){
            cout << length - result << endl;
        }else{
            cout << length - result - 1 << endl;
        }
    }
    return 0;
}