#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>



class robot {
public:
    std::string name() const{
        return current_name;
    };

    robot(){
        newName();
    };
    
    void reset(){
        std::string oldName = current_name;
        newName();
    };

private:
    std::string current_name;
    static std::unordered_set<std::string> namesSet;

    std::string makeName(){

        std::string newName = "";
        for(int i = 0; i < 2; i++){
            newName += 'A' + rand() % 26;
        }
        for(int i = 0; i < 3; i++){
            newName += '0' + rand() % 10;
        }

        return newName;
        
    }


void newName(){
    
        while(true){
            std::string name = makeName();
            if(namesSet.count(name) == 0){
                current_name = name;
                namesSet.emplace(name);
                break;
            }

        }
}

};

std::unordered_set<std::string> robot::namesSet;

int main(){

    std::vector<robot> robots;
    


    for(int i = 0;i < 10; i++){
        robots.push_back(robot());
        std::cout << robots.back().name() << "\n";
    }


    robots[7].reset();
   // std::cout << robots[7].name() << "\n";
 
    return 0;
}
    


