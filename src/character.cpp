#include "character.hpp"

Character::Character(EntityTypeId typeId, const std::string & name, float maxLife, Direction dir, float speed,
                     const sf::Vector2f & pos)
 : Living(typeId, name, maxLife, dir, pos, speed)
{
    c_Bag = new Bag;
}
Character::~Character()
{
    delete c_Bag;
    c_Bag = NULL;
}

void Character::update(const sf::Time & elapsed)
{
     c_TurnTime += elapsed;

     Living::update(elapsed);
}

bool Character::isMoveable()
{
    if(c_TurnTime.asSeconds() >= 0.1)
        return Living::isMoveable();
    return false;
}

bool Character::takeItem(const Item * item, uint16_t nbr)
{
    return c_Bag->addItem(item, nbr);
}

void Character::removeItem(const Item * item, uint16_t nbr)
{
    for(uint16_t i = 0; i < c_Bag->getNbrItems(); i++)
    {
        if(item == c_Bag->getItem(i))
        { // si le joueur a ien un item comme celui la dans son sac
            c_Bag->removeItem(i, nbr); // on en retire 'nbr'
            break;
        }
    }
}

const Item * Character::getItem(uint16_t i) const
{
    return c_Bag->getItem(i);
}
