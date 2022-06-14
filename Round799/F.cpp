#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        int dict[10];
        for(int i = 0; i < 10; i++){
            dict[i] = 0;
        }
        for(int i = 0; i < length; i++){
            int number;
            cin >> number;
            dict[number % 10]++;
        }
        bool flag = false;
        for(int i = 0; i < 10 && !flag; i ++){
            for(int j = 0; j < 10 && !flag; j++){
                for(int k = 0;k < 10 && !flag; k++){
                    if((i+j+k)%10 != 3)continue;
                    else{
                        dict[i] --;
                        dict[j] --;
                        dict[k]--;
                        if(dict[i] >= 0&& dict[j] >=0&&dict[k]>=0){
                            flag = true;
                        }
                        dict[i]++;
                        dict[j]++;
                        dict[k]++;
                    }
                }
            }
        }
        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}