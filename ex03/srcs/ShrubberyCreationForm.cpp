/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:19:30 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/30 15:07:11 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkExecutionRequirements(executor);
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		return;
	ofs <<
	"          v .   ._, |_  .,\n"
	"       `-._\\/  .  \\ /    |/_\n"
	"           \\\\  _\\, y | \\\\\n"
	"     _\\_.___\\\\, \\\\ / -.\\||\n"
	"       `7-,--.`._||  / / ,\n"
	"       /'     `-. `./ / |/_.'\n"
	"                 |    |//\n"
	"                 |_    /\n"
	"                 |-   |\n"
	"                 |   =|\n"
	"                 |    |\n"
	"----------------/ ,  . \\--------._\n";
	ofs.close();
}

std::string const& ShrubberyCreationForm::getTarget() const {
	return _target;
}