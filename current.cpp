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

    std::array<std::string, 10> onesDigits = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };


    std::array<std::string, 10> teens = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };

    std::array<std::string, 10> tensDigits = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };

    std::string wordsFromArray(long num, std::array<std::string, 10>& words){
        return words[num];
    }

    std::string makeWordsFromSections(long section){
        std::string sectionWords = "";
        int onesDigit = section % 10;
        int tensDigit = (section % 100) / 10;
        int hundredsDigit = section / 100;
        if(section < 10) { sectionWords += wordsFromArray(section, onesDigits); }
        else if(section >= 10 && section <= 19) { sectionWords += wordsFromArray(section % 10, teens); }
        else if(section >= 20) { 
            if(section >= 100){
                sectionWords += wordsFromArray(section / 100, onesDigits);
                sectionWords += " hundred";
                if(section % 100 > 0) { sectionWords += " "; }
            }

            sectionWords += wordsFromArray((section % 100) / 10, tensDigits);
            if(onesDigit > 0 && tensDigit > 0) {sectionWords += "-"; }
            sectionWords += wordsFromArray(section % 10, onesDigits);
        }

        return sectionWords;
    }

    std::string makeWords(long num){

        if(num == 0) { return "zero"; }
        std::vector<long> nums = splitIntoGroups(num);

        return makeWordsFromSections(nums[0]);
        
    }



int main(){


    for(int i = 0; i <= 150; i++){
        std::cout << makeWords(i) << "\n";
    }

 
    return 0;
}
    


