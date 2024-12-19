/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_GradeTooLowException.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:01:17 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 10:13:15 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("EXCEPTION THROW : FORM Grade is too low");
}