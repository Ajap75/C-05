/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:19:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/18 19:01:18 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "AForm.hpp"

#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP


class Bureaucrat;

class ShrubberyCreationForm : public virtual AForm
{
    
    std::string _target;

    public :

    //-----------CONSTRUCTOR DESTRUCTOR---------//

    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string _name);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator =(const ShrubberyCreationForm& other);

    //---------MEMBERS FUNCTIONS---------------//
    std::string getTarget() const;
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
