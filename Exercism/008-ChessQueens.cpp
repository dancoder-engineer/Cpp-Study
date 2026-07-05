#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

class chess_board {
public:
    chess_board(std::pair<int,int> white,
                std::pair<int,int> black){

                    if( white.first < 0 || white.second < 0 || black.first < 0 || black.second < 0) {
                        throw std::domain_error("Position below 0, outside board.");
                    }
                    else if( white.first > 7 || white.second > 7 || black.first > 7 || black.second > 7) {
                        throw std::domain_error("Position above 7, outside board.");
                    }
                    else if(white.first == black.first && white.second == black.second){
                        throw std::domain_error("Queens can not occupy the same square.");
                    }
                    else {
                        whitePos = white;
                        blackPos = black;
                    }
                }

    std::pair<int,int> white() const{
        return whitePos;
    }

    std::pair<int,int> black() const{
        return blackPos;
    }

    bool can_attack() const{
        if(whitePos.first == blackPos.first) { return true; }
        else if(whitePos.second == blackPos.second) { return true; }
        else if(abs(whitePos.first - blackPos.first) == abs(whitePos.second - blackPos.second)) { return true; }
        else { return false; }

    }

private:
    std::pair<int, int> whitePos;
    std::pair<int, int> blackPos;
};




int main(){

    
    std::pair<int, int> white = {0, 1};
    std::pair<int, int> black = {0, 1};

    chess_board board = chess_board(white, black);
    


   // std::cout << robots[7].name() << "\n";
 
    return 0;
}
    


