/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:49 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/31 00:03:21 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
}

Intern::Intern(Intern const& other) {
	(void)other;
}

Intern& Intern::operator=(Intern const& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

AForm*	Intern::_createShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_createRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::_createPardon(std::string const& target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const& formName, std::string const& target) const {

	static const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	static AForm* (* const formCreators[3])(std::string const&) = {
		&Intern::_createShrubbery,
		&Intern::_createRobotomy,
		&Intern::_createPardon
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	
	std::cout << "Intern cannot create '" << formName << "': unknown form." << std::endl;
	return NULL;
}
