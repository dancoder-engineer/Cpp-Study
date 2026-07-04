#include <iostream>
#include <string>
#include <vector>

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* sensor){
    return sensor == nullptr;
}




int main(){

    pillar_men_sensor* sensor{nullptr};
    bool isConnected = connection_check(sensor);
 
    return 0;
}
    