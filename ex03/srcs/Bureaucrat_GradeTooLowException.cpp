/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat_GradeTooLowException.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:01:17 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 10:13:08 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("EXCEPTION THROW : BUREAUCRAT Grade is too low");
}