/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:30:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 09:16:45 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "AForm.hpp"

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


class Bureaucrat
{
    private :

    const std::string _name;
    int _grade;
    

    public :
    
    //-----------CONSTRUCTOR DESTRUCTOR---------//
    
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator =(const Bureaucrat& other);

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
    int getGrade() const;
    void increment();
    void decrement();
    void signAForm(AForm& form) const;
    void executeForm(AForm const & form);
};

//---------NO MEMBERS FUNCTIONS---------------//



std::ostream& operator <<(std::ostream& out, const Bureaucrat& other);
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

