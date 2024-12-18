/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:18 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/18 19:11:34 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/ShrubberryCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"


#include "../headers/AForm.hpp"
#include "../headers/Colors.hpp"

int main ()
{
            // BUREAUCRATE TEST //
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

        //------------------ FORM TEST----------------- // 
        

        ShrubberyCreationForm Form1("ShrubberryCreationForm");
        RobotomyRequestForm Form2("car");
        PresidentialPardonForm Form3("car");

        // Form Form2 ("Get Married", 150, 10);

        // Form Form3 ("Get divorced", 25, 10);
        // int i = 0;
        Form1.beSigned(Bureaucrat1); // Form signed normally 
        Bureaucrat1.executeForm(Form1); // Form signed normally 
        Form2.beSigned(Bureaucrat1);
        Form3.beSigned(Bureaucrat1);
        Bureaucrat1.executeForm(Form3);
        // while(i <= 100)
        // {
        //     Bureaucrat1.executeForm(Form2); // Form signed normally 
        //     i++;
        // }

        // Form1.beSigned(Bureaucrat1); // Form cannot be signed because has already been signed

        // Form2.beSigned(Bureaucrat2); // Should throw an Exception, too low level 

        // Form3.beSigned(Bureaucrat3); // 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}