/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/31 00:20:35 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	std::cout << "=== Intern Factory Test ===" << std::endl;

	Intern intern;

	// Test: valid forms
	std::cout << "\n--- Creating ShrubberyCreationForm ---" << std::endl;
	AForm* shrub = intern.makeForm("shrubbery creation", "home");
	if (shrub)
		std::cout << *shrub << std::endl;

	std::cout << "\n--- Creating RobotomyRequestForm ---" << std::endl;
	AForm* robo = intern.makeForm("robotomy request", "HAL9000");
	if (robo)
		std::cout << *robo << std::endl;

	std::cout << "\n--- Creating PresidentialPardonForm ---" << std::endl;
	AForm* pardon = intern.makeForm("presidential pardon", "Nelson Mandela");
	if (pardon)
		std::cout << *pardon << std::endl;

	// Test: invalid form
	std::cout << "\n--- Creating UnknownForm ---" << std::endl;
	AForm* unknown = intern.makeForm("fake form", "target");
	if (!unknown)
		std::cout << "Returned NULL as expected for an unknown form.\n";

	// Clean up
	delete shrub;
	delete robo;
	delete pardon;
	delete unknown;	// Safe: deleting a NULL pointer has no effect

	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}
