#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

private:
    const std::string target_;
};

#endif
