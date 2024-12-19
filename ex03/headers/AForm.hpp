/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:22:12 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/18 17:31:31 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

#ifndef AFORM_HPP
#define AFORM_HPP


class Bureaucrat;

class AForm
{
    private :
    
    const std::string _name;
    bool _status;
    const int _accreditation_to_sign;
    const int _accreditation_to_execute;

    public :

    //-----------CONSTRUCTOR DESTRUCTOR---------//

    AForm();
    AForm(const std::string name, const int accreditation_to_sign, const int accreditation_to_execute, bool status);
    virtual ~AForm();
    AForm(const AForm& other);
    AForm& operator =(const AForm& other);

    //-----------NESTED EXCEPTION CLASSES---------//

    class GradeTooHighException : public std::exception
    {
        public :
        
        virtual const char* what() const throw(); 
        
    };
    class GradeTooLowException  : public std::exception
    {
        public :
        
        virtual const char* what() const throw(); 
    };

    class NotSignedException  : public std::exception
    {
        public :
        
        virtual const char* what() const throw(); 
    };

    //---------MEMBERS FUNCTIONS---------------//
    
    std::string getName() const;
    bool getStatus() const;
    void setStatus();
    int getAccreditation_to_sign() const;
    int getAccreditation_to_execute() const;
    void beSigned(const Bureaucrat& b);
    void beExecuted(const Bureaucrat& b) const;

    //--------PURE VIRTUAL FUNCTION-----------//
    
   virtual void execute(Bureaucrat const & executor) const = 0;

    /* By declaring a PURE VIRTUAL FUNCTION --> = 0, I made the class AForm abstract. Every derived concrete class
    will have to implement her own version of the function*/
    
    
};

//---------NO MEMBERS FUNCTIONS---------------//

std::ostream& operator <<(std::ostream& out, const AForm& other);


#endif













/*
The Exception Classes: GradeTooHighException and GradeTooLowException

- These classes inherit from `std::exception` and override the `what()` function.

- The `virtual` keyword in `what()` ensures polymorphic behavior:
  When the exception is caught through a `std::exception` reference, 
  the derived class's `what()` function will be called, displaying the correct error message.

- If `virtual` is omitted:
    - Calling `what()` directly on a derived class instance will work (static binding).
    - However, through a `std::exception` reference/pointer, only the base class's `what()` is invoked.

- `what()` uses `const char*` instead of `std::string`:
    - `const char*` avoids memory allocation and potential exceptions.
    - It ensures lightweight, efficient behavior and avoids issues when exceptions are thrown.

- Constructors and destructors for these exception classes are not mandatory:
    - The base `std::exception` handles construction and destruction.
    - Custom implementation of `what()` is sufficient to return an appropriate error message.

Example:
    try {
        throw Bureaucrat::GradeTooHighException();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl; // Outputs: "Grade is too high!"
    }
*/
