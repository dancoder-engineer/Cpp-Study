#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>


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

    std::array<std::string, 4> factorsOfThousand = {
        " billion",
        " million",
        " thousand",
        ""
    };

    std::vector<long long> splitIntoGroups(long long num){
    std::vector<long long> groups;
    while(num > 0){
        groups.push_back(num % 1000);
        //std::cout << num % 1000 << "\n";
        //groups.insert(groups.begin(), num % 1000);
        num /= 1000;
    }
    return groups;
}

    std::string wordsFromArray(long long num, std::array<std::string, 10>& words){
        return words[num];
    }

    std::string makeWordsFromSections(long long section){
        std::string sectionWords = "";
        int onesDigit = section % 10;
        int tensDigit = (section % 100) / 10;
        int hundredsDigit = section / 100;
        if(section < 10) { sectionWords += wordsFromArray(section, onesDigits); }
        else if(section >= 10 && section <= 19) { sectionWords += wordsFromArray(section % 10, teens); }
        else if(section >= 20) { 
            if(section >= 100){
                sectionWords += wordsFromArray(hundredsDigit, onesDigits);
                sectionWords += " hundred";
                if(section % 100 > 0) { sectionWords += " "; }
            }

            if(tensDigit == 1) { sectionWords += wordsFromArray(onesDigit, teens); }
            else if (tensDigit > 1) { 
                sectionWords += wordsFromArray(tensDigit, tensDigits); 
                if(onesDigit > 0 && tensDigit > 0) {sectionWords += "-"; }
                sectionWords += wordsFromArray(onesDigit, onesDigits);
            }
            else { sectionWords += wordsFromArray(onesDigit, onesDigits); }
        }

        return sectionWords;
    }

    std::string in_english(long long num){

        if(num == 0) { return "zero"; }
        else if(num > 999999999999) { throw std::domain_error("Numbers can not exceed 999,999,999,999."); }
        else if(num < 0) { throw std::domain_error("Numbers can not be less than zero."); }
        else{
            std::string numInWords = "";
            std::vector<long long> nums = splitIntoGroups(num);

            for (int i = static_cast<int>(nums.size() - 1); i >= 0; i--){
                numInWords += makeWordsFromSections(nums[i]);
                if(i > 0 && nums[i] > 0) { numInWords += factorsOfThousand[3 - i]; }
                if((num % static_cast<long long int>(pow(1000,i)) != 0)) { numInWords += " "; }
         }

            return numInWords;
    }   
        
    }



int main(){

    std::cout << "|" << in_english(2000) << "|"  << "\n";


    for(int i = 0; i <= 100; i++){
      //  std::cout << "|" << in_english(i) << "\n";
    }

 
    return 0;
}
    


