/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:46:17 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 15:59:03 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
	: AForm(other), _target(other._target) {		
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {	
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	checkExecutionRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const& PresidentialPardonForm::getTarget() const {
	return _target;
}