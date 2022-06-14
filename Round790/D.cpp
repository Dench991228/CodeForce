#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case++){
        int count_rows, count_columns;
        cin >> count_rows >> count_columns;
        int sum_cons[count_rows+count_columns];// 坐标和相同的点的和
        int sub_cons[count_rows+count_columns];// 坐标差相同的点的和
        int arr[count_rows][count_columns];
        for(int i = 0; i < count_rows+count_columns; i++){
            sum_cons[i] = 0;
            sub_cons[i] = 0;
        }
        int max_sum = 0;
        for(int current_row = 0; current_row < count_rows; current_row++){
            for(int current_column = 0; current_column < count_columns; current_column++){
                int num;
                cin >> num;
                sum_cons[current_column+current_row] += num;
                sub_cons[current_row-current_column+count_columns] += num;
                arr[current_row][current_column] = num;
            }
        }
        for(int current_row = 0; current_row < count_rows; current_row++){
            for(int current_column = 0; current_column < count_columns; current_column++){
                max_sum = max(max_sum, sum_cons[current_column+current_row]+sub_cons[current_row-current_column+count_columns]-arr[current_row][current_column]);
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}