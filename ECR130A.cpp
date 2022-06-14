#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int count_jumps, initial_energy;
        cin >> count_jumps >> initial_energy;
        int sum = 0;
        int current;
        for(int i = 0; i < count_jumps; i++){
            cin >> current;
            sum += current;
        }
        if(sum <= initial_energy){
            cout << "0" << endl;
        }else{
            cout << sum - initial_energy << endl;
        }
    }
    return 0;
}