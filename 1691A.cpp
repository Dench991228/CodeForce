#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        int *arr = (int *)malloc(length * sizeof(int));
        int count_even = 0, count_odd = 0;
        for(int i = 0; i < length; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0){
                count_even ++;
            }else{
                count_odd ++;
            }
        }
        cout << min(count_even, count_odd) << endl;
    }
    return 0;
}