#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <algorithm>

std::string compress_string(std::string s) {
    std::string outputString = "";
    char gatheringChar = s[0];
    int howManyGathered = 1;
    for(int i = 1; i <= static_cast<int>(s.length()); i++){
        bool dump = false;
            if(i != static_cast<int>(s.length())) {
                if(gatheringChar == s[i]) { howManyGathered++; }
                else { dump = true; }
            }
            else { dump = true; }
            if(dump){
                outputString += gatheringChar;
                outputString += std::to_string(howManyGathered);
                howManyGathered = 1;
                if(i < static_cast<int>(s.length())) { gatheringChar = s[i]; }
            }   
    }
    return outputString;
}

int main(){
    
    std::cout << compress_string("aaabbc") << "\n";


    return 0;
}