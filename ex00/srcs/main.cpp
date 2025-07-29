/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/29 11:23:15 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	std::cout << "=== Test: Exception GradeTooHigh ===" << std::endl;
	try {
		Bureaucrat a("João", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test: Exception GradeTooLow ===" << std::endl;
	try {
		Bureaucrat b("Maria", 149);
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << b << std::endl;

		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	std::cout << "=== Test: Constructor with invalid (too high) grade ===" << std::endl;
	try {
		Bureaucrat c("Invalid", 0);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test: Constructor with invalid (too low) grade ===" << std::endl;
	try {
		Bureaucrat d("Invalid", 151);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test: Copy constructor ===" << std::endl;
	try {
		Bureaucrat original("RandomDude", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught during copy construction: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test: Assignment operator ===" << std::endl;
	try {
		Bureaucrat source("Chief", 100);
		Bureaucrat target("Intern", 10);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "Source: " << source << std::endl;
		std::cout << "Target: " << target << std::endl;
		target = source;
		std::cout << "After assignment:" << std::endl;
		std::cout << "Source: " << source << std::endl;
		std::cout << "Target: " << target << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught during assignment: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
