#include <iostream>

using namespace std;

class instance{
    int hour;
    int minute;
public:
    instance(int h, int m): hour(h), minute(m){}
    bool isPalindrome(){
        return (hour / 10 == minute % 10) && (hour % 10 == minute / 10);
    }
    void addMinute(int m){
        minute += (m%60);
        hour += minute/60;
        minute %= 60;
        hour += (m/60);
        hour %= 24;
    }
    void print(){
        cout << hour+":"+minute << endl;
    }
    bool operator!= (instance &ins){
        return !((hour == ins.hour)&&(minute == ins.minute));
    }
};

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case++){
        int hour, minute;
        char s;
        cin >> hour >> s >> minute;
        int interval;
        cin >> interval;
        instance origin = instance(hour, minute);
        instance moving = origin;
        int count_palindrome = 0;
        moving.addMinute(interval);
        count_palindrome += moving.isPalindrome();
        while(moving != origin){
            moving.addMinute(interval);
            count_palindrome += moving.isPalindrome();
        }
        cout << count_palindrome << endl;
    }
    return 0;
}