#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <unordered_set>

//std::unordered_set<std::string>



class allergy_test{

    public:
        int score;
        std::bitset<8> bits;

        allergy_test(int num){
            score = num;
            if(score > 255) { score = score % 256; }
            bits = std::bitset<8>(score);
        }

        bool is_allergic_to(std::string allergen){
            for(int i = 0; i < 8; i++){
                if(allergies[i] == allergen && bits.test(i)) { 
                    return true;}
            }

            return false;
    }

        std::unordered_set<std::string> get_allergies(){
            std::unordered_set<std::string> theirAllergies;
            for(int i = 0; i < 8; i++){
                if(bits.test(i)) { 
                    theirAllergies.emplace(allergies[i]);
                }
            }

            return theirAllergies;
            
        }


    private:
        const std::array<std::string, 8> allergies = {
            "eggs",
            "peanuts",
            "shellfish",
            "strawberries",
            "tomatoes",
            "chocolate",
            "pollen",
            "cats"
        };


};





int main(){
    
    allergy_test(1).is_allergic_to("eggs");

    return 0;
}
    