#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int participant[4];
        cin >> participant[0];
        int result = 0;
        for(int i = 1; i < 4; i++){
            cin >> participant[i];
            if(participant[i] > participant[0]){
                result ++;
            }
        }
        cout << result << endl;
    }
}