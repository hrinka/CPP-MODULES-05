#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRank("High Rank", 24);
        Bureaucrat lowRank("Low Rank", 150);

        Form formA("FormA", 50, 25);
        Form formB("FormB", 100, 50);

        std::cout << "=== High Rank signs FormA ===" << std::endl;
        formA.beSigned(highRank);
        std::cout << formA << std::endl;

        std::cout << "\n=== Low Rank tries to sign FormB (should fail) ===" << std::endl;
        try {
            formB.beSigned(lowRank);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << formB << std::endl;

        std::cout << "\n=== High Rank signs FormB ===" << std::endl;
        formB.beSigned(highRank);
        std::cout << formB << std::endl;

        std::cout << "\n=== High Rank tries to execute FormA (should succeed) ===" << std::endl;
        try {
            formA.execute(highRank);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n=== Low Rank tries to execute FormB (should fail) ===" << std::endl;
        try {
            formB.execute(lowRank);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
