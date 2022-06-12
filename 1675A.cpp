#include <iostream>

using namespace std;

int main(){
    int count_dog_food, count_cat_food, count_universal_food;
    int count_dog, count_cat;
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case++){
        cin >> count_dog_food >> count_cat_food >> count_universal_food;
        cin >> count_dog >> count_cat;
        int dog_food_needed = max(0, count_dog - count_dog_food);
        int cat_food_needed = max(0, count_cat - count_cat_food);
        if(count_universal_food >= cat_food_needed + dog_food_needed){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}