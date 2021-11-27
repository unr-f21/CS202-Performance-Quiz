#include <iostream>
#include <vector>


const int DATA_LENGTH = 10000;

int main() {
    int method = 0;
    std::cout << "Please enter the method you want to use: fixed array=0, dynamic array = 1, vector = 2" << std::endl;
    std::cin >> method;
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Before: " << usage.ru_maxrss << std::endl;
    auto start = std::chrono:: high_resolution_clock:: now() ;

    switch(method) {
        case 0: {
            std::cout << "Fixed array" << std::endl;
            int data[DATA_LENGTH];
            for (int i = 0; i < DATA_LENGTH; i++)
                data[i] = i;
            break;
        }
        case 1: {
            std::cout << "Dynamic array" << std::endl;
            int *data = new int[DATA_LENGTH];
            for (int i = 0; i < DATA_LENGTH; i++)
                data[i] = i;
            break;
        }
        case 2: {
            std::cout << "Vector" << std::endl;
            std::vector<int> v(DATA_LENGTH);
            for (int i = 0; i < DATA_LENGTH; i++) {
                v.push_back(i);
            }
            break;
        }
        default:
            std::cout << "Invalid method" << std::endl;
            return 0;
    }
    auto end = std::chrono:: high_resolution_clock:: now() ;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "After: " << usage.ru_maxrss << std::endl;
    return 0;
}
