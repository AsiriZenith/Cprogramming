#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // Write C++ code here
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "Year:" << 1900 + ltm->tm_year<<endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   cout << "Time: "<< 5+ltm->tm_hour << ":";
   cout << 30+ltm->tm_min -60 << ":";
   cout << ltm->tm_sec << endl;
    return 0;
}