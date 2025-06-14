#include "Card.hpp"

#include <ostream>
#include <string>

#include "utils.hpp"

Card::Card(Card::Type tp, Card::Color col, int val) :
    type(tp),
    color(col),
    value(val)
{}

Card::Type Card::getType() const {
    return type;
}

void Card::setColor(Color col) {
    color = col;
}

// checks if card1 can be used against card2
bool Card::canBePlayed(const Card& card1, const Card& card2) {
    if (card1.type == Card::Type::kWildCommon ||
        card1.type == Card::Type::kWildDrawFour)
        return true;
    if (card1.type == Card::Type::kCommon && card1.type == card2.type) {
        if (card1.color == card2.color)
            return true;
        if (card1.value == card2.value)
            return true;
        return false;
    }
    if (card1.type == card2.type)
        return true;
    if (card1.color == card2.color)
        return true;
    return false;
}

std::ostream& operator <<(std::ostream& os, const Card& card) {
    std::string str;
    switch (card.color) {
    case Card::Color::kBlue:
        str += "Blue ";
        break;
    case Card::Color::kGreen:
        str += "Green ";
        break;
    case Card::Color::kRed:
        str += "Red ";
        break;
    case Card::Color::kYellow:
        str += "Yellow ";
        break; 
    case Card::Color::kNone:
    default:
        break;
    }

    switch (card.getType()) {
    case Card::Type::kCommon:
        str += std::to_string(card.value);
        break;
    case Card::Type::kReverse:
        str += "Reverse";
        break;
    case Card::Type::kDrawTwo:
        str += "Draw 2";
        break;
    case Card::Type::kSkip:
        str += "Skip";
        break;
    case Card::Type::kWildCommon:
        str += "Wild";
        break;
    case Card::Type::kWildDrawFour:
        str += "Wild Draw 4";
        break;
    case Card::Type::kNone:
    default:
        break;
    }

    switch (card.color) {
    case Card::Color::kBlue:
        textUtils::printInBlue(os, str); 
        break;
    case Card::Color::kGreen:
        textUtils::printInGreen(os, str); 
        break;
    case Card::Color::kRed:
        textUtils::printInRed(os, str); 
        break;
    case Card::Color::kYellow:
        textUtils::printInYellow(os, str); 
        break; 
    case Card::Color::kNone:
    default:
        std::cout << str << std::endl;
        break;
    }
    return os;
}