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

#include "../headers/AForm.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Bureaucrat.hpp"



//-----------------------CONSTRUCTOR  & DESTRUCTOR-----------------------------//


AForm::AForm() : 
    _name("unnamed"), _status(0), _accreditation_to_sign(0), _accreditation_to_execute(0)
{
    std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string name, const int accreditation_to_sign, const int accreditation_to_execute, bool status) :
    _name(name), _status(status), _accreditation_to_sign(accreditation_to_sign), _accreditation_to_execute(accreditation_to_execute) 
{
    std::cout << GREEN << "AForm named : " << this->getName() << " constructor called" << RESET << std::endl;
    if (accreditation_to_execute < 1 || accreditation_to_sign < 1)
    {
        throw(AForm::GradeTooHighException());
    }
    if (accreditation_to_execute > 150 || accreditation_to_sign > 150)
    {
        throw(AForm::GradeTooLowException());
    }
}

AForm::~AForm()
{
    std::cout << RED << "AForm named : " << this->getName() << " Destructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other) : 
    _name(other._name), _status(0), _accreditation_to_sign(other._accreditation_to_sign), _accreditation_to_execute(other._accreditation_to_execute) 
{
    std::cout << BLUE << "AForm copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator =(const AForm& other) // Not very relevant in this situation as almost every attributs are const
{
    std::cout << BLUE << "AForm assignation operator called" << RESET << std::endl;
    if (this != &other)
    {
        _status = other._status;
    }
    return (*this);
}


//---------------------------MEMBER FUNCTIONS--------------------------------//

std::string AForm::getName() const 
{
    return(_name);
}
bool AForm::getStatus() const 
{
    return (_status);
}

int AForm::getAccreditation_to_execute() const 
{
    return (_accreditation_to_execute);
}
int AForm::getAccreditation_to_sign() const
{
    return (_accreditation_to_sign);
}

void AForm::setStatus()
{
    if (_status == 0)
        _status = 1;
    return ;
}

void AForm::beSigned(const Bureaucrat& b) 
{
    if (b.getGrade() <= this->getAccreditation_to_sign() && this->getStatus() == false)
    {
        this->setStatus();
        b.signAForm(*this, true);
    }
    else if (b.getGrade() <= this->getAccreditation_to_sign() && this->getStatus() == true)
    {
        b.signAForm(*this, false);
    }
    else
    {
        throw(AForm::GradeTooLowException());
    }
}

 void AForm::beExecuted(const Bureaucrat& b) const
 {
    if (this->getStatus() == false)
        throw(AForm::NotSignedException());
    else if (b.getGrade() >= this->getAccreditation_to_execute())
        throw(AForm::GradeTooHighException());
    else if (b.getGrade() <= this->getAccreditation_to_execute() && this->getStatus() == true)
    {
        std::cout << "The Form type" << this->getName() << GREEN << " is signed and the parmission is granted to " << b.getName() << " to execute the Form" << RESET << std::endl;
    }
 }


//-----------------------------OVERLOADED OPERATOR (NO-MEMBER FUNCTION)---------------------------------//

std::ostream& operator <<(std::ostream& out, const AForm& other)
{
    out << "----------AForm DETAILS-----------" << std::endl;
    out << "NAME : " << other.getName() << std::endl;
    out << "STATUS (1 = SIGNED) : " << other.getName() << std::endl;
    out << "GRADE TO EXECUTE THE AForm : " << other.getAccreditation_to_execute() << std::endl;
    out << "GRADE TO SIGN THE AForm : " << other.getAccreditation_to_sign() << std::endl;
    out << "---------------------------------" << std::endl;
    
    return (out);
}


