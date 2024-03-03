/*
** EPITECH PROJECT, 2024
** NtsTmpRepo
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_
#include <cstddef>
#include "ComponentType.hpp"
#include "Tristate.hpp"

namespace nts {
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
