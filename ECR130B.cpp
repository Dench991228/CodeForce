#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cout << sizeof(long long) << endl;
    long long count_items, count_queries;
    cin >> count_items >> count_queries;
    int *prices = (int*)malloc(sizeof(int)*count_items);
    for(int i = 0; i < count_items;i++){
        cin >> prices[i];
    }
    sort(prices, prices+count_items, greater<int>());
    long long *prefix = (long long*)malloc(sizeof(long long)*count_items);
    long long current_sum = 0;
    for(int i = 0; i < count_items; i++){
        current_sum += prices[i];
        prefix[i] = current_sum;
    }
    for(int current_query = 0; current_query < count_queries; current_query ++){
        int count_purchase, count_free;
        cin >> count_purchase >> count_free;
        if(count_purchase != count_free){// 不是全免单
            cout << prefix[count_purchase - 1] - prefix[count_purchase - count_free -1] << endl;
        }else{
            cout << prefix[count_purchase - 1] << endl;
        }
    }
    return 0;
}