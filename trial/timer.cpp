#include <chrono>
#include <string>
#include <iostream>

using namespace std;
int main() {

    // Start the timer
    auto start = std::chrono::steady_clock::now();
    int i;
    // Game loop
    while (true) {
        // Check the elapsed time
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        // Update the timer text
      cout<<"Time: " << duration <<" seconds"<<endl;

    }
    //this is a just comment for git
    return 0;
}