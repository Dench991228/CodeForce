#include <iostream>

using namespace std;

int main(){
    int count_tickets;
    cin >> count_tickets;
    for(int current_ticket = 0; current_ticket < count_tickets; current_ticket ++){
        string ticket;
        cin >> ticket;
        int sum = 0;
        for(int i = 0; i < 3; i++){
            sum += (ticket[i]-'0');
        }
        for(int i = 3; i < 6; i++){
            sum -= (ticket[i]-'0');
        }
        if(sum == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}