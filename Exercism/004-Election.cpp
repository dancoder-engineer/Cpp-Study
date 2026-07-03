#include <iostream>
#include <algorithm>
#include <vector>

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& result){
    return result.votes;
}

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& result, int increaseBy){
    result.votes += increaseBy;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult>& final_count){

    int winningId = 0;

    for(int i = 1; i < static_cast<int>(final_count.size()); i++){
        if(final_count[i].votes > final_count[winningId].votes) { winningId = i; }
    }

    ElectionResult& winning = final_count[winningId];
    winning.name = "President " + winning.name;
    return winning;
}



int main(){
    ElectionResult ham{"Alex", 1804};
    std::cout << vote_count(ham) << std::endl;
    increment_vote_count(ham, 9);
    std::cout << vote_count(ham) << std::endl;

    ElectionResult sanchez{"Pedro", 471};
    ElectionResult wheatley{"Summer", 340};
    std::vector<ElectionResult> final_count{sanchez, wheatley};

    ElectionResult& winner = determine_result(final_count);
    std::cout << winner.name << std::endl;
    return 0;
}
    