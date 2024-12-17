/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:30:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/17 15:01:54 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


class Bureaucrat
{
    private :

    const std::string _name;
    int _grade;
    

    public :
    
    //constructor destructor;
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

    //member functions
    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();
};


std::ostream& operator <<(std::ostream& out, const Bureaucrat& other);
#endif

