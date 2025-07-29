/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:18:00 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/29 17:16:17 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;

public:
	// Orthodox Canonical Form
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Accessors
	const std::string&  getName() const;
	int                 getGrade() const;

	// Grade modification
	void                incrementGrade();
	void                decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	// Signing
	void signForm(Form& form);
};

// Non-member function
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif

