/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:20:03 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/29 17:14:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Assignment operator
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		// _name, _gradeToSign and _gradeToExecute are const: cannot assign
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
Form::~Form() {
}

// Getters
const std::string&	Form::getName() const {
	return _name;
}

bool	Form::isSigned() const {
	return _isSigned;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// beSigned
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "grade too high";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "grade too low";
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form '" << form.getName() << "' [sign grade: " << form.getGradeToSign()
	   << ", exec grade: " << form.getGradeToExecute()
	   << ", is signed: " << (form.isSigned() ? "yes" : "no") << "]";
	return os;
}
