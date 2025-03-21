/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:22:12 by antoinejour       #+#    #+#             */
/*   Updated: 2025/03/21 10:56:53 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

#ifndef FORM_HPP
#define FORM_HPP


class Bureaucrat;

class Form
{
    private :
    
    const std::string _name;
    bool _status;
    const int _accreditation_to_sign;
    const int _accreditation_to_execute;

    public :

    //-----------CONSTRUCTOR DESTRUCTOR---------//

    Form();
    Form(const std::string name, const int accreditation_to_sign, const int accreditation_to_execute);
    ~Form();
    Form(const Form& other);
    Form& operator =(const Form& other);

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

    //---------MEMBERS FUNCTIONS---------------//
    
    std::string getName() const;
    bool getStatus() const;
    void setStatus();
    int getAccreditation_to_sign() const;
    int getAccreditation_to_execute() const;
    void beSigned(const Bureaucrat& b);
    
    
};

//---------NO MEMBERS FUNCTIONS---------------//

std::ostream& operator <<(std::ostream& out, const Form& other);


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
