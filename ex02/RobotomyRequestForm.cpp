#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target_(target) {
    std::srand(std::time(0)); // ランダムシードを初期化
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << target_ << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target_ << "!" << std::endl;
    }
}
