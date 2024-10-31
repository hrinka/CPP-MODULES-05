#include "AForm.hpp"

// コンストラクタ
AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute)
    : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {}

// ゲッター関数
const std::string& AForm::getName() const {
    return name_;
}

bool AForm::isSigned() const {
    return is_signed_;
}

int AForm::getGradeToSign() const {
    return grade_to_sign_;
}

int AForm::getGradeToExecute() const {
    return grade_to_execute_;
}

// フォームにサインする
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign_) {
        throw GradeTooLowException();
    }
    is_signed_ = true;
}

// 例外メッセージ
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// 出力オペレータのオーバーロード
std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
    os << Aform.getName() << ", Aform status: " << (Aform.isSigned() ? "signed" : "not signed")
       << ", required grade to sign: " << Aform.getGradeToSign()
       << ", required grade to execute: " << Aform.getGradeToExecute();
    return os;
}
