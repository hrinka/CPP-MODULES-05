#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
