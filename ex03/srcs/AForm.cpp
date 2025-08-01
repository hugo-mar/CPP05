/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:20:03 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 12:35:58 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		// _name, _gradeToSign and _gradeToExecute are const: cannot assign
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
AForm::~AForm() {
}

// Getters
const std::string&	AForm::getName() const {
	return _name;
}

bool	AForm::isSigned() const {
	return _isSigned;
}

int	AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

// beSigned
void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Permission to execute
void	AForm::checkExecutionRequirements(Bureaucrat const& executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

// Exceptions
const char*	AForm::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "grade too low";
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return "form not signed";
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form '" << form.getName()
	   << "' [sign grade: " << form.getGradeToSign()
	   << ", exec grade: " << form.getGradeToExecute()
	   << ", is signed: " << (form.isSigned() ? "yes" : "no") << "]";
	return os;
}
