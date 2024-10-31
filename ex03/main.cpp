#include <iostream>
#include "Intern.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat alice("Alice", 5);  // 高い権限を持つBureaucrat
    Bureaucrat bob("Bob", 75);     // 中程度の権限を持つBureaucrat

    std::cout << "Testing form creation and execution:\n" << std::endl;

    // ロボトミーフォームの生成とテスト
    Form* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomyForm) {
        std::cout << "Form created successfully: " << robotomyForm->getName() << std::endl;
        try {
            robotomyForm->beSigned(alice);  // Aliceがフォームに署名
            robotomyForm->execute(alice);   // Aliceがフォームを実行
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete robotomyForm;
    }

    // シュラブベリーフォームの生成とテスト 
    Form* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (shrubberyForm) {
        std::cout << "Form created successfully: " << shrubberyForm->getName() << std::endl;
        try {
            shrubberyForm->beSigned(bob);  // Bobが署名
            shrubberyForm->execute(bob);   // Bobが実行
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete shrubberyForm;
    }

    // 大統領恩赦フォームの生成とテスト
    Form* pardonForm = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (pardonForm) {
        std::cout << "Form created successfully: " << pardonForm->getName() << std::endl;
        try {
            pardonForm->beSigned(alice);   // Aliceが署名
            pardonForm->execute(alice);    // Aliceが実行
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete pardonForm;
    }

    // 存在しないフォームの生成テスト
    Form* unknownForm = someRandomIntern.makeForm("unknown form", "Target");
    if (!unknownForm) {
        std::cerr << "Failed to create form: unknown form does not exist." << std::endl;
    }

    return 0;
}
