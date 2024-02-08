/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:44:24 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:44:21 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <iostream>
# define NO_COMMAND_ERROR "You didn't enter command, please enter one of these commands : 'ADD', 'SEARCH', 'EXIT'.\n\n"
# define COMMAND_NOT_FOUND_ERROR "This command doesn't exist, please enter one of these commands : 'ADD', 'SEARCH', 'EXIT'.\n\n"

void	add_contact(PhoneBook *phonebook);
void	search_contact(PhoneBook *phonebook);
bool	get_input_not_empty(std::string input_msg, std::string &input_res);

# define TITLE "      :::::::::       :::    :::       ::::::::       ::::    :::       ::::::::::       :::::::::       ::::::::       ::::::::       :::    :::          :::        :::::::: \n\
     :+:    :+:      :+:    :+:      :+:    :+:      :+:+:   :+:       :+:              :+:    :+:     :+:    :+:     :+:    :+:      :+:   :+:          :+:        :+:    :+: \n\
    +:+    +:+      +:+    +:+      +:+    +:+      :+:+:+  +:+       +:+              +:+    +:+     +:+    +:+     +:+    +:+      +:+  +:+          +:+ +:+           +:+ \n\
   +#++:++#+       +#++:++#++      +#+    +:+      +#+ +:+ +#+       +#++:++#         +#++:++#+      +#+    +:+     +#+    +:+      +#++:++          +#+  +:+         +#+ \n\
  +#+             +#+    +#+      +#+    +#+      +#+  +#+#+#       +#+              +#+    +#+     +#+    +#+     +#+    +#+      +#+  +#+        +#+#+#+#+#+     +#+ \n\
 #+#             #+#    #+#      #+#    #+#      #+#   #+#+#       #+#              #+#    #+#     #+#    #+#     #+#    #+#      #+#   #+#             #+#      #+# \n\
###             ###    ###       ########       ###    ####       ##########       #########       ########       ########       ###    ###            ###     ##########"

#endif