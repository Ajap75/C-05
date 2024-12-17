/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_Excetion_GradeTooHighException.cpp            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:01:17 by antoinejour       #+#    #+#             */
/*   Updated: 2024/12/17 15:38:38 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("FORM Grade is too hign");
}