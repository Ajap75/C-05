/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:30:58 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/16 17:40:43 by antoinejour      ###   ########.fr       */
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


    //member functions
    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();
};


std::ostream& operator <<(std::ostream& out, const Bureaucrat& other);
#endif

