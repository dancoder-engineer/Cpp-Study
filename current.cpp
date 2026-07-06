#include <iostream>
#include <string>
#include <vector>



std::string noOfBottles(int num){
    if(num == 0) { return "No more bottles"; }
    std::string numString = std::to_string(num);
    std::string howManyBottles = numString + "bottle";
    if(num > 1) { howManyBottles += "s"; }
    return howManyBottles;
}

std::string verse(int num){
    //99 bottles of beer on the wall, 99 bottles of beer.
    //Take one down and pass it around, 98 bottles of beer on the wall.
    std::string line1 = noOfBottles(num) + " bottles of beer on the wall, " + noOfBottles(num) +  " bottles of beer.\n";
    std::string line2 = "";
    if(num - 1 == 0) {
        line2 = "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
    }
    else{
        line2 = "Take one down and pass it around, " + noOfBottles(num - 1) + " bottles of beer on the wall.\n";

    }

}

    

int main(){

  
    std::cout << verse(5) << "\n";
 
    return 0;
}