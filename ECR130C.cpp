#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        int length;
        cin >> length;
        string s,t;
        cin >> s >> t;
        s = "a"+s+"c";
        t = "a"+t+"c";
        // 遍历两个字符串，看看a与c的相对顺序是否一样，通过底下的b的数量来判断是不是相配
        int s_iter = 0, t_iter = 0;
        int borrow = 0;// 最右边是a，b的数量比t少，向右扩展
        int cache = 0;// 最右边是c，b的数量比t多，向左移动
        bool success = true;
        while(s_iter != s.length() && t_iter != t.length()){
            int b_segement = 0;// t字符串到上一处有多少个b
            char t_this;// 当前t字符是a还是c
            while(t[t_iter] != 'a' && t[t_iter] != 'c'){
                t_iter ++;
                b_segement ++;
            }
            t_this = t[t_iter];
            int passed = 0;// 过掉多少b
            char s_this;
            while(s[s_iter] != 'a' && s[s_iter] != 'c'){
                s_iter ++;
                passed ++;
            }
            s_this = s[s_iter];
            //cout << s_this << t_this << endl;
            s_iter++;
            t_iter++;
            if(s_this != t_this){// 相对顺序不一样
                cout << "NO" << endl;
                success = false;
                break;
            }
            passed -= borrow;// 实际过掉的
            borrow = 0;
            passed += cache;
            cache = 0;
            if(s_this == 'c'){
                if(passed < 0 || passed < b_segement){// 没有足够多的b
                    cout << "NO" << endl;
                    success = false;
                    break;
                }else if(passed == 0 && passed != b_segement) {
                    cout << "NO" << endl;
                    success = false;
                    break;
                }else{
                    cache = passed - b_segement;
                }
            }else{
                if(passed <= b_segement){// 如果b太少了，就找后面借，因为是a所以可以一直从右边借
                    borrow = b_segement - passed;
                }else if(passed > b_segement){// 如果b太多了，就挂了
                    cout << "NO" << endl;
                    success = false;
                    break;
                }
            }
        }
        if(success)cout << "YES" << endl;
    }
    return 0;
}