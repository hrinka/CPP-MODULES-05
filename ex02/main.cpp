#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 2);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Arthur Dent");

        shrubberyForm.beSigned(bureaucrat);
        shrubberyForm.execute(bureaucrat);

        robotomyForm.beSigned(bureaucrat);
        robotomyForm.execute(bureaucrat);

        pardonForm.beSigned(bureaucrat);
        pardonForm.execute(bureaucrat);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}