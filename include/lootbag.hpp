#ifndef LOOTBAG_HPP
#define LOOTBAG_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Bag.hpp"

class LootBag : public Bag, public Entity
{
    public:
        LootBag(const sf::Vector2f & position = sf::Vector2f(0, 0));
        LootBag(const std::vector< BagCell > & items, const sf::Vector2f & position = sf::Vector2f(0, 0));
        virtual ~LootBag();

        virtual bool addItem(const Item * item, uint16_t nbr);
        virtual void removeItem(uint16_t i, uint16_t nbr);

    private:
};

#endif // LOOTBAG_HPP
