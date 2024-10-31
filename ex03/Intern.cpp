#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <map>

Intern::Intern() {}
Intern::~Intern() {}

// 関数ポインタのエイリアスを定義
typedef Form* (*FormCreator)(const std::string& target);

Form* createRobotomyRequest(const std::string& target) { return new RobotomyRequestForm(target); }
Form* createShrubberyCreation(const std::string& target) { return new ShrubberyCreationForm(target); }
Form* createPresidentialPardon(const std::string& target) { return new PresidentialPardonForm(target); }

Form* Intern::makeForm(const std::string& formName, const std::string& target) {
    // フォーム名と作成関数の対応マップ
    std::map<std::string, FormCreator> formCreators;
    formCreators["robotomy request"] = createRobotomyRequest;
    formCreators["shrubbery creation"] = createShrubberyCreation;
    formCreators["presidential pardon"] = createPresidentialPardon;

    // 指定されたフォーム名がマップにあるかを確認
    std::map<std::string, FormCreator>::iterator it = formCreators.find(formName);
    if (it != formCreators.end()) {
        std::cout << "Intern creates " << formName << std::endl;
        return it->second(target); // 関数ポインタを呼び出してフォームを生成
    } else {
        std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
        return nullptr;
    }
}
