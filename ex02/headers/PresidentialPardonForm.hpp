/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:19:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/18 19:00:30 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "AForm.hpp"

#ifndef PRESIDENTILPARDONFORM_HPP
#define PRESIDENTILPARDONFORM_HPP


class Bureaucrat;

class PresidentialPardonForm : public virtual AForm
{
    
    std::string _target;

    public :

    //-----------CONSTRUCTOR DESTRUCTOR---------//

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string _name);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator =(const PresidentialPardonForm& other);

    //---------MEMBERS FUNCTIONS---------------//
    
    std::string getTarget() const;
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
