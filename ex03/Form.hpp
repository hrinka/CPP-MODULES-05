#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
public:
    // コンストラクタとデストラクタ
    Form(const std::string& name, int grade_to_sign, int grade_to_execute);
    virtual ~Form();

    // ゲッター関数
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // メンバ関数
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

    // 例外クラス
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form has not been signed yet.";
        }
    };

private:
    const std::string name_;
    bool is_signed_;
    const int grade_to_sign_;
    const int grade_to_execute_;
};

// 出力オペレータのオーバーロード
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
