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
#include "../headers/OutputFormat.hpp"
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
    std::srand(std::time(nullptr)); // seed for the generator based on current time.
    if (std::rand() % 2 == 0) // 50% chance : take a random number,  
    {
        std::cout << GREEN << this->getTarget() << " has been robotomized successfully " << RESET << std::endl;
    }
    else
    {
        std::cout << RED << this->getTarget() << " failed to be robotomized" << RESET << std::endl;
    }
}

/* Seed and Determinism:
If you do not seed the random number generator (using std::srand()), the pseudo-random sequence will start from the same initial value every time the program runs. This makes it deterministic (the same sequence will repeat each time you run the program).
If you use std::srand(std::time(nullptr)), it seeds the generator with the current time, providing a different starting point for the random number sequence for each execution of the program */



