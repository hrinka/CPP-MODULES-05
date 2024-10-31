#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("Presidential Pardon", 25, 5), target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw Form::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw Form::GradeTooLowException();
    }

    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
