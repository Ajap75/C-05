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

#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Bureaucrat.hpp"
#include "fstream"



//-----------------------CONSTRUCTOR  & DESTRUCTOR-----------------------------//


RobotomyRequestForm::RobotomyRequestForm() : 
    AForm::AForm(), _target("unnamedtarget")
{
    std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45, 0), _target(target)
{
    std::cout << GREEN << "RobotomyRequestForm constructor with parameter called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED << "RobotomyRequestForm Destructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm::AForm(other), _target(other._target)
{
    std::cout << BLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& other) // Not very relevant in this situation as almost every attributs are const
{
    std::cout << BLUE << "RobotomyRequestForm assignation operator called" << RESET << std::endl;
    AForm::operator =(other);
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

//--------------------------------------MEMBER FUNCTIONS ---------------------------------------//

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

//---------------------------MEMBER FUNCTIONS OVERIDING THE BASE CLASS FUNCTION EXECUTE()--------------------------------//


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->beExecuted(executor);
    std::cout << RED << "DRRRRRIIIIIIIIIIIzzz bssss ccrrak" << RESET << std::endl;
    if (std::rand() % 2 == 0) // 50% chance
    {
        std::cout << GREEN << this->getTarget() << "has been robotomized successfully " << RESET << std::endl;
    }
    else
    {
        std::cout << RED << this->getTarget() << " failed to be robotomized" << RESET << std::endl;
    }
}



