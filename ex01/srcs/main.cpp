/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/29 23:44:54 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Immigration Office: The Work Permit Saga ===" << std::endl;

    Form residencyApp("Residency Application", 10, 8);
    Form workPermit("Work Permit", 5, 3);

    std::cout << residencyApp << std::endl;
    std::cout << workPermit << std::endl;
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

    std::cout << "[Aboubakar Camara] tries to sign 'Residency Application':" << std::endl;
    applicant.signForm(residencyApp);

    std::cout << "[Carla Fernandes] tries to sign 'Residency Application':" << std::endl;
    clerk.signForm(residencyApp);

    std::cout << "[Dr. António Silva] tries to sign 'Work Permit':" << std::endl;
    supervisor.signForm(workPermit);

    std::cout << "[Aboubakar Camara] tries to sign 'Work Permit':" << std::endl;
    applicant.signForm(workPermit);

    std::cout << std::endl << "=== Forms Status After All Procedures ===" << std::endl;
    std::cout << residencyApp << std::endl;
    std::cout << workPermit << std::endl;

    return 0;
}
