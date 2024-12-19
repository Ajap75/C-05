/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:18 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 12:53:57 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/ShrubberryCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/AForm.hpp"
#include "../headers/OutputFormat.hpp"
#include "../headers/OutputFormat.hpp"
#include "../headers/Intern.hpp"

int main ()
{
           
    try 
    { 
        //------------------- BUREAUCRATE TEST ----------------------//
        
        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 1 : BUREAUCRATES HAVE A GRADE THAT FITS IN BOUND" << RESET << std::endl << std::endl;

        Bureaucrat Bureaucrat1("John", 1);
        // Bureaucrat Bureaucrat1("John", 0);

        Bureaucrat Bureaucrat2("Andrea", 149);
        // Bureaucrat Bureaucrat2("Andrea", 150);

        Bureaucrat Bureaucrat3("Karim", 2);
        // Bureaucrat Bureaucrat3("Karim", 1);

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 1 : OK" << RESET << std::endl;

        //------------------ INCREMENT DECREMENT FUNCTION TESTS ----------------- // 
        
        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 2 : THE DECREMENT AND INCREMENT FUNCTION" << RESET << std::endl << std::endl;
    
        Bureaucrat1.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat2.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat3.increment();

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 2 OK : THE DECREMENT AND INCREMENT FUNCTION DO THE JOB PROPERLY" << RESET << std::endl;

        //------------------ FORM TEST----------------- // 
        
        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 3 : FORM CREATION" << RESET << std::endl << std::endl;
        
        ShrubberyCreationForm home("home");
        RobotomyRequestForm car("car");
        PresidentialPardonForm Tony("Tony");
        PresidentialPardonForm notsigned("B21");

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 3 OK : THE FORM HAVE BEEN PROPERLY CREATED" << RESET << std::endl;
        
        
        //---------------- SIGNING FORM TEST ------------//
        
        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 4 : SIGNING FORM" << RESET << std::endl << std::endl;
        
        
        Bureaucrat1.signAForm(home); 
        Bureaucrat1.signAForm(home); // Re-sign form test
        // Bureaucrat2.signAForm(car); // Low Accreditation Test
        // Bureaucrat2.signAForm(Tony); // Low Accreditation Test
        Bureaucrat1.signAForm(car); 
        Bureaucrat1.signAForm(Tony); 
        

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 4 OK :THE FORM HAVE BEEN PROPERLY SIGNED" << RESET << std::endl;

        
        //--------------EXECUTE FORM TEST ------------------//

        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 5 : EXECUTING FORM" << RESET << std::endl << std::endl;

            Bureaucrat1.executeForm(Tony);
            Bureaucrat1.executeForm(home); // Form signed normally 
            Bureaucrat1.executeForm(car);
            // Bureaucrat1.executeForm(notsigned); // Try to execute an unsigned form. 
            // Bureaucrat2.executeForm(Tony);
            

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 5 OK : FORMS HAVE BEEN SUCCESSFULLY EXECUTED" << RESET << std::endl << std::endl;
        

         //--------------CREATION FORM BY INTERN ------------------//
         
        std::cout << std::endl << UNDERLINE_YELLOW << YELLOW << "TEST 6 : INTERN CREATES FORMS" << RESET << std::endl << std::endl;
        
        Intern I = Intern();
        AForm* form1 = I.makeForm("ShrubberryCreationForm", "Home");
        delete form1;
        AForm* form2 = I.makeForm("RobotomyRequestForm", "Pepper");
        delete form2;
        AForm* form3 = I.makeForm("PresidentialPardonForm", "King");
        delete form3;
        // AForm* form4 = I.makeForm("NotAfForm", "King");
        // delete form4;

        std::cout << std::endl << UNDERLINE_GREEN << GREEN << "TEST 6 OK : INTERN SUCCESSFULLY CREATED FORMS" << RESET << std::endl << std::endl;
        std::cout << std::endl << GREEN << "ALL TEST PASSED" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}