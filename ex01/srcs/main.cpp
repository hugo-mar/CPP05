/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/06 23:31:28 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	std::cout << "=== Immigration Office: The Work Permit Saga ===" << std::endl;

	Form residencePermit("Residence Permit", 10, 8);
	Form workAuthorisation("Work Authorisation", 5, 3);

	std::cout << residencePermit << std::endl;
	std::cout << workAuthorisation << std::endl;
	std::cout << std::endl;

	try {
		Form impossibleForm("Request for Permanent Happiness", 0, 10);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << " (No such thing in this office!)" << std::endl;
	}
	try {
		Form lostCause("Request for Family Reunification", 10, 200);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << " (No such thing in this office!)" << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat applicant("Aboubakar Camara", 12);
	Bureaucrat clerk("Carla Fernandes", 20);
	Bureaucrat supervisor("Dr. António Silva", 2);

	std::cout << applicant << std::endl;
	std::cout << clerk << std::endl;
	std::cout << supervisor << std::endl;
	std::cout << std::endl;

	std::cout << "[Aboubakar Camara] tries to sign 'Residence Permit':" << std::endl;
	applicant.signForm(residencePermit);

	std::cout << "[Carla Fernandes] tries to sign 'Residence Permit':" << std::endl;
	clerk.signForm(residencePermit);

	std::cout << "[Dr. António Silva] tries to sign 'Work Authorisation':" << std::endl;
	supervisor.signForm(workAuthorisation);

	std::cout << "[Aboubakar Camara] tries to sign 'Work Authorisation':" << std::endl;
	applicant.signForm(workAuthorisation);

	std::cout << std::endl << "=== Forms Status After All Procedures ===" << std::endl;
	std::cout << residencePermit << std::endl;
	std::cout << workAuthorisation << std::endl;

	return 0;
}
