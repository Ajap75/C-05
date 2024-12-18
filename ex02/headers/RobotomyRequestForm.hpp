/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:19:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/18 19:01:14 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "AForm.hpp"

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


class Bureaucrat;

class RobotomyRequestForm : public virtual AForm
{
    
    std::string _target;

    public :

    //-----------CONSTRUCTOR DESTRUCTOR---------//

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string _name);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator =(const RobotomyRequestForm& other);

    //---------MEMBERS FUNCTIONS---------------//
    std::string getTarget() const;
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
