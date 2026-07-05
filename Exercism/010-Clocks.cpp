#include <iostream>
#include <string>
#include <vector>

namespace date_independent {

    class clock{

        public:

        long time() const{
            return currentMinute;
        }

        static clock at(long hour, long minute){
            return clock(hour * 60 + minute);
        }

        clock plus(int minutes){
            int minute = normalize(currentMinute + minutes);
            return at(minute / 60, minute % 60);
        }

        operator std::string() const{
            long hour = currentMinute / 60;
            long minute = currentMinute % 60;
            return doubleDigitString(hour) + ":" + doubleDigitString(minute);
        }

        bool operator==(const clock& other) const{
            return currentMinute == other.time();
        }

        bool operator!=(const clock& other) const{
            return currentMinute != other.time();
        }



        private:

        long currentMinute;
        

        clock(long minute){
            currentMinute = normalize(minute);
        }

        static long normalize(long minute){
            minute = minute % 1440;
            if(minute < 0) { minute += 1440; }
            return minute;
        }

        static std::string doubleDigitString(long num){
            std::string numString = std::to_string(num);
            return num >= 10 ? numString : "0" + numString; 
        }
        

    };


}

int main(){

    date_independent::clock testClock = date_independent::clock::at(0, -15);
    std::cout <<  static_cast<std::string>(testClock);

 
    return 0;
}