#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;

private:
    const std::string target_;
};

#endif
