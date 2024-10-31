#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw Form::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw Form::GradeTooLowException();
    }

    std::ofstream file(target_ + "_shrubbery");
    if (file.is_open()) {
        file << "                      ___" << std::endl;
        file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
        file << "             ,-'          __,,-- \\" << std::endl;
        file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
        file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
        file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
        file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
        file << "     (     ,-'                  `." << std::endl;
        file << "      `._,'     _   _             ;" << std::endl;
        file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
        file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
        file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
        file << "                \"Hb HH dF" << std::endl;
        file << "                 \"HbHHdF" << std::endl;
        file << "                  |HHHF" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  dHHHb" << std::endl;
        file << "                .dFd|bHb.               o" << std::endl;
        file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
        file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
        file << "##########################################" << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << target_ + "_shrubbery" << std::endl;
        throw std::runtime_error("Failed to open file");
    }
}
