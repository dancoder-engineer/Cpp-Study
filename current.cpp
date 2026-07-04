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

std::vector<double> scaleRecipe (const std::vector<double> originalAmounts, double factor){
    std::vector<double> newAmounts;
    for(double amount:originalAmounts){
        newAmounts.push_back(amount * (factor / 2));
    }
    return newAmounts;
}

void addSecretIngredient(std::vector<std::string>& myList, const std::string& secretIngredient){
    myList.back() = secretIngredient;
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

    std::vector<double> quantities{1.2, 3.6, 10.5};
    for(double i:quantities) { std:: cout << i << " || "; }
    std::cout << std::endl;
    std::vector<double> uppedQuantities{scaleRecipe(quantities, 4)};
    // => { 2.4, 7.2, 21 }
    for(double i:uppedQuantities) { std:: cout << i << " || "; }
    std::cout << std::endl;

    std::vector<std::string> myList2{"noodles", "meat", "sauce", "mozzarella", "?"};
    std::string secretIngredient{"spice melange"};
    std::cout << myList2.back() << std::endl;
    addSecretIngredient(myList2, secretIngredient);
    std::cout << myList2.back() << std::endl;
    // myList => {"noodles", "meat", "sauce", "mozzarella", "spice melange"}

    return 0;
}
    