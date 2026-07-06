#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class anagram{

    public:

    anagram(std::string initialWord){
        anagramWord = initialWord;
        wordAsAVector = sortAndClean(initialWord);
    }


    std::vector<std::string> matches(std::vector<std::string> words){

        std::vector<std::string> anagrams;

        for(std::string word:words){
            bool isAnagram = true;
            if(lowerCaseWord(anagramWord) == lowerCaseWord(word)) { continue; }
            std::vector<char> compareWordVector = sortAndClean(word);
            if(wordAsAVector.size() != compareWordVector.size()) { continue; }
            for(int i = 0; i < static_cast<int>(wordAsAVector.size()); i++){
                if(wordAsAVector[i] != compareWordVector[i]) { isAnagram = false; }
            }
            if(isAnagram) { anagrams.push_back(word); }
        }

        return anagrams;
    }

    private:
        std::string anagramWord;
        std::vector<char> wordAsAVector;

        std::vector<char> sortAndClean(std::string word){
            std::vector<char> wordVector;

            for(char c:word){
                wordVector.push_back(std::tolower(c));
            }

            sort(wordVector.begin(), wordVector.end());

            return wordVector;
        }

        std::string lowerCaseWord(std::string word){
            std::string lowerCase;
            for(char c:word){
                lowerCase += std::tolower(c);
            }
            return lowerCase;
        }

        

        

};
    

int main(){

    return 0;
}