#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ - 1 < 1) {
        throw GradeTooHighException();
    }
    grade_--;
}

void Bureaucrat::decrementGrade() {
    if (grade_ + 1 > 150) {
        throw GradeTooLowException();
    }
    grade_++;
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}//add

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
