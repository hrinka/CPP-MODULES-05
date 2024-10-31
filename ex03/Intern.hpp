#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    Form* makeForm(const std::string& formName, const std::string& target);
};

#endif
