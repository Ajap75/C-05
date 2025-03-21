/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:18 by antoinejour       #+#    #+#             */
/*   Updated: 2025/03/21 10:58:19 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/Colors.hpp"

int main ()
{
            // BUREAUCRATE TEST //
    try 
    {
        Bureaucrat Bureaucrat1("John", 1);
        // Bureaucrat Bureaucrat1("John", 0);

        Bureaucrat Bureaucrat2("Andrea", 148);
        // Bureaucrat Bureaucrat2("Andrea", 150);

        Bureaucrat Bureaucrat3("Karim", 2);
        // Bureaucrat Bureaucrat3("Karim", 1);


    
        Bureaucrat1.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat2.decrement();
        std::cout << "__________" << std::endl;
        Bureaucrat3.increment();

        //------------------ FORM TEST----------------- // 
        

        Form Form1 ("Kill a man", 2, 1);
        std::cout << Form1 << std::endl;

        Form Form2 ("Get Married", 148, 10);
        std::cout << Form2 << std::endl;

        Form Form3 ("Get divorced", 25, 10);
        std::cout << Form3 << std::endl;


        Form1.beSigned(Bureaucrat1); // Form signed normally
        std::cout << Form1 << std::endl;
        Form1.beSigned(Bureaucrat1); // Form cannot be signed because has already been signed
        std::cout << Form1 << std::endl;
        Form2.beSigned(Bureaucrat2); // Should throw an Exception, too low level 
        std::cout << Form2 << std::endl;
        Form3.beSigned(Bureaucrat3); //
        std::cout << Form3 << std::endl;
 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}