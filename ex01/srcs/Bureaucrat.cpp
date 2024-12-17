/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:30:56 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/17 17:12:23 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Form.hpp"

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(1) 
{
    std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
     if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
    std::cout << GREEN << "Bureaucrat named : " << getName() <<  " default constructor called with parameters called" << RESET << std::endl;
    
};

Bureaucrat::~Bureaucrat()
{
    std::cout << RED <<"Bureaucrat named : " << getName() <<  " default destructor called" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _grade(other._grade) 
{
    std::cout << MAGENTA << "Bureaucrat copy constructor called" << RESET << std::endl;
};

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& other)
{
    std::cout << BLUE << "Bureaucrat assignation operator called" << RESET << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
    }
    return (*this);
};

//-----------------------------------------METHODS-----------------------------------------------------//

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::increment()
{
    if (getGrade() < 2)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Actual situation of the Bureaucrat : " << std::endl << *this << std::endl;
    _grade--;
    std::cout << GREEN "PROMOTION" << RESET << std::endl;
    std::cout << "New situation of the Bureaucrat : " << std::endl << *this << std::endl;
}

void Bureaucrat::decrement()
{
    if (getGrade() > 149)
        throw GradeTooLowException();
    std::cout << "Actual situation of the Bureaucrat : " << std::endl << *this << std::endl;
    _grade++;
    std::cout << RED "DEMOTION" << RESET << std::endl;
    std::cout << "New situation of the Bureaucrat : " << std::endl << *this << std::endl;
}

void Bureaucrat::signForm(Form& form, bool action) const
{
    if (form.getStatus() == true && action == true)
        std::cout << this->getName() << GREEN << " signed " << RESET << form.getName() << std::endl;
    else if (form.getStatus() == true && action == false)
        std::cout << this->getName() << RED << " couldn't signed " << form.getName() << "because the form was ALREADY SIGNEDS" << RESET << std::endl;
    else if (form.getStatus() == false && action == false)
        std::cout << this->getName() << RED << " couldn't signed " << form.getName() << "because his grade of " << this->getGrade() << RESET << "is below the required accreditation grade of " << form.getAccreditation_to_sign() <<  "to sign the form "  << std::endl;
}



//-----------------------------OVERLOADED OPERATOR (NO-MEMBER FUNCTION---------------------------------//



std::ostream& operator <<(std::ostream& out, const Bureaucrat& other)
{
    std::cout << BLUE << "OVERLOADED <<  OPERATOR CALLED" << RESET << std::endl;
    out <<  "Bureaucrate Name = " << MAGENTA << other.getName() << RESET << std::endl;
    out  << "Bureaucrate Grade = "  << MAGENTA<< other.getGrade() << RESET << std::endl;
    return (out);  
};


