/*
** EPITECH PROJECT, 2024
** NtsTmpRepo
** File description:
** AComponent
*/
#include "IComponent.hpp"
#include "AComponent.hpp"

namespace nts {
    void AComponent::simulate(std::size_t tick) {
        return;
    }

    Tristate AComponent::compute(std::size_t pin) {
        return Tristate::Undefined;
    }

    void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin) {
        return;
    }
}