#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;

private:
    const std::string target_;
};

#endif
