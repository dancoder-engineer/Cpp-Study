#include <iostream>
#include <string>
#include <vector>



std::string noOfBottles(int num){
    if(num == 0) { return "no more bottles"; }
    std::string numString = std::to_string(num);
    std::string howManyBottles = numString + " bottle";
    if(num > 1) { howManyBottles += "s"; }
    return howManyBottles;
}

std::string verse(int num){
    //99 bottles of beer on the wall, 99 bottles of beer.
    //Take one down and pass it around, 98 bottles of beer on the wall.
    std::string line1 = noOfBottles(num) + " of beer on the wall, " + noOfBottles(num) +  " of beer.\n";
    std::string line2 = "";
    if(num == 0) {
        line2 = "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        line1[0] = std::toupper(line1[0]);
    }
    else if(num == 1) {
        line2 = "Take it down and pass it around, no more bottles of beer on the wall.\n";
    }
    else{
        line2 = "Take one down and pass it around, " + noOfBottles(num - 1) + " of beer on the wall.\n";
    }
    return line1 + line2;
}

std::string sing(int num, int end = 0){
    std::string song = "";
    for(int i = num; i >= end; i--){
        song += verse(i);
        if(i > end) { song += "\n"; }
    }
    return song;
}

    

int main(){

  
    std::cout << verse(0) << "\n";
 
    return 0;
}