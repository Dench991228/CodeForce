#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        int *arr = (int*)malloc(sizeof(int)*length);
        int sum = 0;
        for(int i = 0; i < length; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        bool flag = false;
        for(int i = 0; i < length; i++){
            if((double)arr[i] == sum*1.0/length){
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if(!flag)cout << "NO" << endl;
    }
    return 0;
}