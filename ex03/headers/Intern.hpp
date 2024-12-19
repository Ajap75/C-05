/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:58:53 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 12:41:25 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "string"
#include "iostream"
#include "AForm.hpp"

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{
    private :

    public :
    
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator =(const Intern& other);

    // ---- MEMEBER FUNCTION ----- // 

    AForm* makeForm(const std::string& type_of_form, const std::string& target_of_form);

    //-----------NESTED EXCEPTION CLASSES---------//

    class UnfindableForm : public std::exception
    {
        public :
        
        virtual const char* what() const throw(); 
        
    };

};

#endif