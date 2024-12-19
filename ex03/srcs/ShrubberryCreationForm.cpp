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

#include "../headers/ShrubberryCreationForm.hpp"
#include "../headers/OutputFormat.hpp"
#include "../headers/Bureaucrat.hpp"
#include "fstream"



//-----------------------CONSTRUCTOR  & DESTRUCTOR-----------------------------//


ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm::AForm(), _target("unnamedtarget")
{
    std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137, 0), _target(target)
{
    std::cout << GREEN << "ShrubberyCreationForm constructor with parameter called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RED << "ShrubberyCreationForm Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm::AForm(other), _target(other._target)
{
    std::cout << BLUE << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& other) // Not very relevant in this situation as almost every attributs are const
{
    std::cout << BLUE << "ShrubberyCreationForm assignation operator called" << RESET << std::endl;
    AForm::operator =(other);
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

//--------------------------------------MEMBER FUNCTIONS ---------------------------------------//

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}
//---------------------------MEMBER FUNCTIONS OVERIDING THE BASE CLASS FUNCTION EXECUTE()--------------------------------//


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->beExecuted(executor);
    std::cout << GREEN << "A file named : " << this->getTarget() << "_shrubberry has been created in the currebnt directory with a ASCCI TREE in it" << RESET << std::endl;
    int i;
    int j;
    int k;
    int height;
    height = 10;
    int trunkHeight = height / 3;
    int t = 0;

    std::ofstream file(this->getTarget() + "_shruberry");
    if (!file)
    {
        std::cerr << "Error opening file : " << this->getTarget() << std::endl;
        return;
    }

    i = 0;
    while (i <= height)
    {
        j = 0;
        while (j <= height - i - 1)
        {
            file << " "; 
            ++j;
        }
        k = 0;
        while (k <= 2 * i + 1)
        {
            file << "*"; 
            ++k;
        }
        file << std::endl; // Ajout du retour à la ligne après chaque branche
        ++i;
    }

    while (t < trunkHeight)
    {
        j = 0;
        while (j < height - 1) 
        {
            file << " ";
            j++;
        }
        file << "|" << std::endl;
        t++;
    }
}



