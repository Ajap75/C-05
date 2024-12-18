/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:37:20 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/17 17:18:22 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Bureaucrat.hpp"
#include "fstream"



//-----------------------CONSTRUCTOR  & DESTRUCTOR-----------------------------//


PresidentialPardonForm::PresidentialPardonForm() : 
    AForm::AForm(), _target("unnamedtarget")
{
    std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5, 0), _target(target)
{
    std::cout << GREEN << "PresidentialPardonForm constructor with parameter called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED << "PresidentialPardonForm Destructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm::AForm(other), _target(other._target)
{
    std::cout << BLUE << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& other) // Not very relevant in this situation as almost every attributs are const
{
    std::cout << BLUE << "PresidentialPardonForm assignation operator called" << RESET << std::endl;
    AForm::operator =(other);
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

//--------------------------------------MEMBER FUNCTIONS ---------------------------------------//

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

//---------------------------MEMBER FUNCTIONS OVERIDING THE BASE CLASS FUNCTION EXECUTE()--------------------------------//


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->beExecuted(executor);
    std::cout << this->getTarget() << GREEN << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}


