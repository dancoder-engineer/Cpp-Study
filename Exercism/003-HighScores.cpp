#include <iostream>
#include <algorithm>
#include <vector>

class HighScores {
   private:
    std::vector<int> scores;

   std::vector<int> newSortedList(){
    std::vector<int> sortedScores = scores;
    sort(sortedScores.begin(), sortedScores.end());
    return sortedScores;
   }

   public:
    HighScores(std::vector<int> scores) : scores(scores){};

    std::vector<int> list_scores() {
        // TODO: Return all scores for this session.
        return scores;
    }

    int latest_score() {
        // TODO: Return the latest score for this session.
        return scores.back();
    }

    int personal_best() {
        // TODO: Return the highest score for this session.
        std::vector<int> sortedScores = newSortedList();
        return sortedScores.back();
}

    std::vector<int> top_three() {
        // TODO: Return the top 3 scores for this session in descending order.
        std::vector<int> sortedScores = newSortedList();
        std::vector<int> highScores;

        for(int i = 0; i < 3; i++){
            if(static_cast<int>(sortedScores.size()) > i) { highScores.push_back(sortedScores[sortedScores.size()-(i+1)]); }
        }

        return highScores;
    }
    
};


int main(){
    
    return 0;
}
    