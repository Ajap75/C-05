/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:18 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/16 18:39:37 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/GradeTooHighException.hpp"
#include "../headers/GradeTooLowException.hpp"
#include "../headers/Bureaucrat.hpp"
#include "../headers/Colors.hpp"

int main ()
{
    try 
    {
        Bureaucrat Bureaucrat1("John", 1);
        // Bureaucrat Bureaucrat1("John", 0);

        Bureaucrat Bureaucrat2("Andrea", 149);
        // Bureaucrat Bureaucrat2("Andrea", 150);

        Bureaucrat Bureaucrat3("Karim", 2);
        // Bureaucrat Bureaucrat3("Karim", 1);


    
        Bureaucrat1.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat2.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat3.increment();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}