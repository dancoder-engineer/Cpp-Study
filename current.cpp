#include <iostream>
#include <string>
#include <vector>

struct amount { int noodles; double sauce; };


amount quantities(std::vector<std::string> layers){
     //For each noodle layer in your lasagna, you will need 50 grams of noodles.
     //For each sauce layer in your lasagna, you will need 0.2 liters of sauce.
     amount ret = {0, 0.0};
     for (std::string layer:layers){
        if(layer == "noodles") { ret.noodles += 50; }
        else if(layer == "sauce") { ret.sauce += 0.2; }
     }
     return ret;
}


int preparationTime(std::vector<std::string> layers, int avgTime = 2){
    return layers.size() * avgTime;
}

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList){
    myList.back() = friendsList.back();
}




int main(){
    std::vector<std::string> layers{"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"};
    std::cout << preparationTime(layers, 3) << std::endl;
    // => 18
    std::cout << preparationTime(layers) << std::endl;
    // => 12

    amount needed = quantities({"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"});
    std::cout << "Noodles: " << needed.noodles << std::endl;
    std::cout << "Sauce: " << needed.sauce << std::endl;

    std::vector<std::string> friendsList{"noodles", "sauce", "mozzarella", "kampot pepper"};
    std::vector<std::string> myList{"noodles", "meat", "sauce", "mozzarella", "?"};
    std::cout << myList.back() << std::endl;
    addSecretIngredient(myList, friendsList);
    std::cout << myList.back() << std::endl;
    return 0;
}
    