/*
** EPITECH PROJECT, 2024
** NtsTmpRepo
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            void simulate(std::size_t tick) override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
    };
}


#endif /* !ACOMPONENT_HPP_ */
