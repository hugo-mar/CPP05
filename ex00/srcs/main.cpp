/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/28 19:37:09 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		// Create a Bureaucrat with valid grade
		Bureaucrat a("João", 2);
		std::cout << a << std::endl;

		// Increment grade (should become 1, the highest)
		a.incrementGrade();
		std::cout << a << std::endl;

		// Attempt to increment beyond the highest grade (should throw)
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Create a Bureaucrat near the lowest grade
		Bureaucrat b("Maria", 149);
		std::cout << b << std::endl;

		// Decrement grade (should become 150, the lowest)
		b.decrementGrade();
		std::cout << b << std::endl;

		// Attempt to decrement beyond the lowest grade (should throw)
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }

	// Test constructor with invalid (too high) grade
	try {
		Bureaucrat c("Invalid", 0);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test constructor with invalid (too low) grade
	try {
		Bureaucrat d("Invalid", 151);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test copy constructor
	try {
		Bureaucrat original("CopyMe", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught during copy construction: " << e.what() << std::endl;
	}

	// Test assignment operator
	try {
		Bureaucrat source("Source", 100);
		Bureaucrat target("Target", 10);
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

	return 0;
}
