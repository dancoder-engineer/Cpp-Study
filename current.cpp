#include <iostream>
#include <array>
#include <string>
#include <vector>

std::vector<long> splitIntoGroups(long num){
    std::vector<long> groups;
    while(num > 0){
        //groups.push_back(num % 1000);
        groups.insert(groups.begin(), num % 1000);
        num /= 1000;
    }
    return groups;
}

std::string oneToTen(int i){
    std::array numNames = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    return numNames[i];
}

std::string teens(int i){
    std::array numNames = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };
    return numNames[i % 10];
}


int main(){

    std::vector<long> vect = splitIntoGroups(99999);
    for(int i = 0; i < static_cast<int>(vect.size()); i++){
        std::cout << vect[i] << "\n";
    }

 
    return 0;
}
    


