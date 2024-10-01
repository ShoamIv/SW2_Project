
#ifndef MONOPOLY_PLAYER_HPP
#define MONOPOLY_PLAYER_HPP
#include <string>
#include <vector>
#include "Estate.hpp"
#include "Dice.hpp"
/**
 * Player header file
 *
 * This header defines the Player class, which represents a player in the Monopoly game.
 * The class handles player-specific details such as their name, current position,
 * amount of cash, estates they own, and other gameplay-related properties.
 */
class Board;
const float BOARD_WIDTH = 800;
const float BOARD_HEIGHT = 800;
const float SQUARE_SIZE = 73;
const float R = 10.0f;
enum class PlayerColor {
    Red,
    Blue,
    Green,
    Yellow,
    Orange,
    Purple,
    Brown,
    Magenta
};

class Player {
    std::string name;
    PlayerColor  color;
    int id;
    int curr_position=0;                //current position in the game.
    int cash=0;                         // holds for the money the player has.
    int jail_time=0;
    int dice{};                        //recent diceRoll.
    int NumOfRailRoad=0;
    int getOutFromJail=0;
    int DoubleCount=0;
    bool ChanceDraw=false;
    bool Bankruptcy=false;
    std::vector<Estate*> Estates;       //Player Estates

    //GUI Related fields and Methods:
    sf::Text text;
    sf::Font font;
    void InitializePlayer(sf::RenderWindow &window);
    sf::CircleShape PlayerInfoCircle;

public:
    explicit Player(std::string &name,PlayerColor color,int id,sf::RenderWindow& window);
    //setters:
    void setCash(int amount);
    void setJail(int time);
    void IncreaseNumRailRoad();
    void setChanceDraw(bool flag);
    void IncreaseJailCard();
    void setBankruptcy();
    void setJailCard(int num);
    void AddEstate(Estate &estate);
    void setRecentDice(int diceroll);
    //getters:
    std::string getName();
    [[nodiscard]] int getCash() const;
    [[nodiscard]] int getJail() const;
    [[nodiscard]] int getRecentDice() const;
    [[nodiscard]] int getRailRoad() const;
    int getPosition() const;
    int getID() const;
    int getJailCard() const;
    bool getChanceDraw() const;
    bool getBankruptcy() const;
    int getPositionIndex(const std::string& location);
    sf::CircleShape & getCircle();
    std::vector<Estate*> getEstates();

    //IN-Game Methods:
    void CollectRent(Player &p,int rent);
    void Move(int steps,sf::RenderWindow &window);
    void MoveTo(const std::string& location,sf::RenderWindow &window);
    void resetRepeatDouble();
    void CollectBankruptcy(Player & BrokePlayer);

    //GUI Update Player, Method:
    void DrawInfo(sf::RenderWindow &window);

    const sf::Color &getColor();
};


#endif //MONOPOLY_PLAYER_HPP
