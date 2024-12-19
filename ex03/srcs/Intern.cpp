/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:04:20 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 12:53:11 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"
#include "../headers/OutputFormat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberryCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"





Intern::Intern()
{
    std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}
Intern::~Intern()
{
    std::cout << RED << "Intern default destructor called" << RESET << std::endl;
}
Intern::Intern(const Intern& other)
{
    std::cout << BLUE << "Intern Coppy Constructor called" << RESET << std::endl;
    (void) other;
}

Intern& Intern::operator =(const Intern& other)
{
    std::cout << MAGENTA << "Intern assignation operator called" << RESET << std::endl;
    if (this != &other)
    {}
    return (*this);
}


// ---- MEMEBER FUNCTION ----- // 

AForm* Intern::makeForm(const std::string& type_of_form, const std::string& target_of_form)
{
    int i;
    i = 0;
    std::string Forms[3];
    Forms[0] = "ShrubberryCreationForm";
    Forms[1] = "RobotomyRequestForm";
    Forms[2] = "PresidentialPardonForm";
    while (i < 3)
    {
        if (Forms[i] == type_of_form)
        {
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target_of_form);
                case 1:
                    return new RobotomyRequestForm(target_of_form);
                case 2:
                    return new PresidentialPardonForm(target_of_form);
            }
        }
        i++;
    }
    throw(UnfindableForm());
}
