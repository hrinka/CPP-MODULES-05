#include "Form.hpp"

// コンストラクタ
Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
    : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw GradeTooLowException();
    }
}

Form::~Form() {}

// ゲッター関数
const std::string& Form::getName() const {
    return name_;
}

bool Form::isSigned() const {
    return is_signed_;
}

int Form::getGradeToSign() const {
    return grade_to_sign_;
}

int Form::getGradeToExecute() const {
    return grade_to_execute_;
}

// フォームにサインする
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign_) {
        throw GradeTooLowException();
    }
    is_signed_ = true;
}

// 例外メッセージ
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// 出力オペレータのオーバーロード
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", form status: " << (form.isSigned() ? "signed" : "not signed")
       << ", required grade to sign: " << form.getGradeToSign()
       << ", required grade to execute: " << form.getGradeToExecute();
    return os;
}
