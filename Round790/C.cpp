#include <iostream>
#include <vector>

using namespace std;

int cmp(string s, string t){
    string::iterator s_iter = s.begin(), t_iter = t.begin();
    int dis = 0;
    while(s_iter != s.end()){
        dis += abs((*s_iter) - (*t_iter));
        s_iter++;
        t_iter++;
    }
    return dis;
}

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case++){
        int count_words, length_word;
        cin >> count_words >> length_word;
        int distance[count_words];
        vector<string> strings = vector<string>();
        int min_dis = 0x7fffffff;
        for(int i = 0; i < count_words; i++){
            string s;
            cin >> s;
            for(int j = 0; j<i;j++){
                min_dis = min(cmp(strings[j],s), min_dis);
            }
            strings.push_back(s);
        }
        cout << min_dis << endl;
    }
    return 0;
}