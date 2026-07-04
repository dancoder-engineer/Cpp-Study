#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::unordered_set<std::string> names;

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
        names.erase(oldName);
    };

private:
    std::string current_name;

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
            if(names.count(name) == 0){
                current_name = name;
                break;
            }

        }
}

};

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
    


