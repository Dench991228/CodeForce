#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_test_case = 0; current_test_case < count_test_cases; current_test_case ++){
        int count_boxes;
        cin >> count_boxes;
        int box;
        int sum = 0, mini = 0x7fffffff;
        for(int i = 0; i < count_boxes; i ++){
            cin >> box;
            sum += box;
            mini = min(box, mini);
        }
        cout << sum - mini * count_boxes << endl;
    }
    return 0;
}