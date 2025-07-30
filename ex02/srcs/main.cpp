/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 16:54:04 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	
	std::cout << "=== executor started ===" << std::endl << std::endl;

	Bureaucrat aboubakar("Aboubakar Camara", 1);
	Bureaucrat random("Random Guy", 45);
	Bureaucrat junior("Junior Clerk", 140);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robo("Mr. Robot");
	PresidentialPardonForm pardon("Nelson Mandela");

	std::cout << "[TEST] Signature attempts:" << std::endl;
	std::cout << "-> Junior Clerk tries to sign 'ShrubberyCreationForm':" << std::endl;
	junior.signForm(shrub);
	std::cout << "-> Random Guy tries to sign 'RobotomyRequestForm':" << std::endl;
	random.signForm(robo);
	std::cout << "-> Junior Clerk tries to sign 'PresidentialPardonForm':" << std::endl;
	junior.signForm(pardon);
	std::cout << "-> Aboubakar tries to sign 'PresidentialPardonForm':" << std::endl;
	aboubakar.signForm(pardon);
	std::cout << std::endl;

	std::cout << "[TEST] Executing signed forms:" << std::endl;
	std::cout << "-> Junior Clerk tries to execute 'ShrubberyCreationForm' (should fail: grade too low):" << std::endl;
	junior.executeForm(shrub);
	std::cout << "-> Aboubakar tries to execute 'ShrubberyCreationForm':" << std::endl;
	aboubakar.executeForm(shrub);
	std::cout << "-> Random Guy tries to execute 'RobotomyRequestForm' 3 times:" << std::endl;
	random.executeForm(robo);
	random.executeForm(robo);
	random.executeForm(robo);
	std::cout << "-> Aboubakar tries to execute 'PresidentialPardonForm':" << std::endl;
	aboubakar.executeForm(pardon);
	std::cout << std::endl;

	std::cout << "[TEST] Attempting to execute unsigned form:" << std::endl;
	PresidentialPardonForm notSigned("Unknown Candidate");
	std::cout << "-> Aboubakar tries to execute 'PresidentialPardonForm' (unsigned):" << std::endl;
	aboubakar.executeForm(notSigned);
	std::cout << std::endl;

	std::cout << std::endl << "=== End of tests ===" << std::endl;
	return 0;
}
