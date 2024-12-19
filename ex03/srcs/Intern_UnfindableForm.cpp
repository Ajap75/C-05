/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_UnfindableForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:39:33 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/19 12:51:37 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

const char* Intern::UnfindableForm::what() const throw()
{
    return ("!!!!!!!!THE FORM ASKED IS UNFINDABLE!!!!!!");
}