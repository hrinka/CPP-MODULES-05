#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

private:
    const std::string target_;
};

#endif
