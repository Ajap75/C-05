/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:37:20 by antoinejour       #+#    #+#             */
/*   Updated: 2025/03/21 11:02:07 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Form.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Bureaucrat.hpp"



//-----------------------CONSTRUCTOR  & DESTRUCTOR-----------------------------//


Form::Form() : 
    _name("unnamed"), _status(0), _accreditation_to_sign(0), _accreditation_to_execute(0)
{
    std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, const int accreditation_to_sign, const int accreditation_to_execute) :
    _name(name), _status(0), _accreditation_to_sign(accreditation_to_sign), _accreditation_to_execute(accreditation_to_execute) 
{
    std::cout << GREEN << "Form named : " << this->getName() << " constructor called" << RESET << std::endl;
    if (accreditation_to_execute < 1 || accreditation_to_sign < 1)
    {
        throw(Form::GradeTooHighException());
    }
    if (accreditation_to_execute > 150 || accreditation_to_sign > 150)
    {
        throw(Form::GradeTooLowException());
    }
}

Form::~Form()
{
    std::cout << RED << "Form named : " << this->getName() << " Destructor called" << RESET << std::endl;
}

Form::Form(const Form& other) : 
    _name(other._name), _status(0), _accreditation_to_sign(other._accreditation_to_sign), _accreditation_to_execute(other._accreditation_to_execute) 
{}

Form& Form::operator =(const Form& other) // Not very relevant in this situation as almost every attributs are const
{
    std::cout << BLUE << "Form assignation operator called" << RESET << std::endl;
    if (this != &other)
    {
        _status = other._status;
    }
    return (*this);
}


//---------------------------MEMBER FUNCTIONS--------------------------------//

std::string Form::getName() const 
{
    return(_name);
}
bool Form::getStatus() const
{
    return (_status);
}

int Form::getAccreditation_to_execute() const 
{
    return (_accreditation_to_execute);
}
int Form::getAccreditation_to_sign() const
{
    return (_accreditation_to_sign);
}

void Form::setStatus()
{
    if (_status == 0)
        _status = 1;
    return ;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->getAccreditation_to_sign() && this->getStatus() == false)
    {
        this->setStatus();
        b.signForm(*this, true);
    }
    else if (b.getGrade() <= this->getAccreditation_to_sign() && this->getStatus() == true)
    {
        b.signForm(*this, false);
    }
    else
    {
        throw(Form::GradeTooLowException());
    }
}


//-----------------------------OVERLOADED OPERATOR (NO-MEMBER FUNCTION)---------------------------------//

std::ostream& operator <<(std::ostream& out, const Form& other)
{
    out << "----------FORM DETAILS-----------" << std::endl;
    out << "NAME : " << other.getName() << std::endl;
    out << "STATUS (1 = SIGNED) : " << other.getStatus() << std::endl;
    out << "GRADE TO SIGN THE FORM : " << other.getAccreditation_to_sign() << std::endl;
    out << "GRADE TO EXECUTE THE FORM : " << other.getAccreditation_to_execute() << std::endl;
    out << "---------------------------------" << std::endl;
    
    return (out);
}


