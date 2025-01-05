#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10, sum = 0;      // Variable initialization
    for (int i = 0; i < 5; ++i) {    // Loop to calculate sum
        sum += a + b;                 // Assigning sum of a and b to sum
        cout << "Iteration " << i + 1 << ": sum = " << sum << endl; // Print sum at each iteration
        a += 2;                       // Update a in each iteration
        b += 3;                       // Update b in each iteration
    }
    return 0;
}


//#include <iostream>
//#include <stdexcept>  // For throwing and catching exceptions
//using namespace std;
//
//int main() {
//    int a = 5, b = 10, sum = 0;      // Variable initialization
//    try {
//        for (int i = 0; i < 5; ++i) {    // Loop to calculate sum
//            sum += a + b;                 // Assigning sum of a and b to sum
//            cout << "Iteration " << i + 1 << ": sum = " << sum << endl; // Print sum at each iteration
//            a += 2;                       // Update a in each iteration
//            b += 3;                       // Update b in each iteration
//
//            // Throw an exception if sum exceeds 50
//            if (sum > 50) {
//                throw std::runtime_error("Sum exceeded 50!"); // Exception thrown here
//            }
//        }
//    }
//    catch (const std::runtime_error& e) {   // Catching the exception
//        cout << "Exception caught: " << e.what() << endl;  // Output the exception message
//    }
//
//    return 0;
//}
