#include <iostream>
#include <string>

std::string initialCleaning(std::string& str){
    std::string newString = "";
        for(char c:str){
            if(c == '[' || c == ']' || c == '(' || c == ')' || c == '{' || c == '}'){ newString += c; }
        }
        return newString;
}


int findFirstFromRight(std::string str){
    for(int i = static_cast<int>(str.length()); i >= 0; i--){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') { return i; }
    }

    return -1;
}

int backPart(std::string& str, int openingLocation){

    char badChar1 = ']';
    char badChar2 = ')';
    char badChar3 = '}';
    char endChar;

    if(str[openingLocation] == '{') { 
        endChar = '}'; 
        badChar3 = 'j';
    }

    else if (str[openingLocation] == '[' ) { 
        endChar = ']';
        badChar1 = 'j';
    }

    else { 
        endChar = ')';
        badChar2 = 'j';
        }

        


    for(int i = openingLocation; i < static_cast<int>(str.length()); i++){
        if(str[i] == badChar1 || str[i] == badChar2 || str[i] == badChar3) { break; }
        if(str[i] == endChar) { return i; }
    }
    return -1;
    


}

std::string cleanString(std::string& str, int loc1, int loc2){

    std::string newString = "";
    for(int i = 0; i < static_cast<int>(str.length()); i++){
        if(i != loc1 && i != loc2) { newString += str[i]; }
    }
    return newString;

}

bool check(std::string str){

    str = initialCleaning(str);
    

    while(true){ 
        if(str.empty()) { return true; }
        int openingLocation = findFirstFromRight(str);
        if(str[0] != '{' && str[0] != '[' && str[0] != '(') { return false; }
        int backLocation = backPart(str, openingLocation);
        if(backLocation == -1) { return false; }
        str = cleanString(str, openingLocation, backLocation);
    }


    }



    