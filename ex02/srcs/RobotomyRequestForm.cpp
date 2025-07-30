/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:01:13 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 16:11:35 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
	:AForm(other), _target(other._target) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	checkExecutionRequirements(executor);

	static bool seeded = false;
	if (!seeded) {
		srand(std::time(0));
		seeded = true;
	}

	std::cout << "* Drrrrrrrrrrr... drrr... drrrr... *" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }
}

std::string const& RobotomyRequestForm::getTarget() const {
	return _target;
}