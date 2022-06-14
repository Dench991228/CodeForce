#include <iostream>

using namespace std;

int main(){
    int count_test_cases;
    cin >> count_test_cases;
    for(int current_case = 0; current_case < count_test_cases; current_case ++){
        char chessBoard[8][8];
        // 接收棋盘参数
        for(int row = 0; row < 8; row++){
            for(int col = 0; col < 8; col++){
                cin >> chessBoard[row][col];
            }
        }
        // 准备开始判断有没有国王
        for(int row = 1; row <= 6; row ++){
            for(int col = 1; col <= 6; col ++){
                if(chessBoard[row][col] == '#' && chessBoard[row-1][col-1] == '#' && chessBoard[row+1][col+1] == '#' && chessBoard[row-1][col+1] == '#' && chessBoard[row+1][col-1] == '#'){
                    cout << row+1 << " " << col+1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}