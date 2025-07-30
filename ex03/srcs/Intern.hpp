/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:25:10 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 19:00:30 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& target) const;

private:
	static AForm*	_createShrubbery(const std::string& target);
	static AForm*	_createRobotomy(const std::string& target);
	static AForm*	_createPardon(const std::string& target);
};

#endif
