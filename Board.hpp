#ifndef MONOPOLY_BOARD_HPP
#define MONOPOLY_BOARD_HPP
#include "Button.hpp"
#include <vector>
#include <memory>
#include "Estate.hpp"
#include "Button.hpp"
#include "SpecialSquare.hpp"
/**
 * @class Board
 * @brief The `Board` class represents the game board in Monopoly, managing all squares and their graphical representation.
 * The `Board` class is a singleton responsible for initializing, managing, and drawing the Monopoly game board.
 * It holds all the squares (properties, special squares, etc.), handles interactions between players and the board,
 * and draws the squares and board components on the window.
 */
class Board {
    Board();
    static Board * ptr;
    std::vector<std::unique_ptr<Square>> board;
    void initializeBoard();
    void addSquare(std::unique_ptr<Square> square);  // Accept unique_ptr for derived classes
    [[nodiscard]] sf::Color getSquareColor(const std::unique_ptr<Square>& square) const;
    std::vector<std::pair<sf::RectangleShape, sf::Text>> graphicalSquares;  // Stores the graphical representation of squares
    void drawSectionName(const std::string &name, float x, float y, sf::RenderWindow &window);
    Button button;

public:
    /**
     * Draw board.
     * @param window
     */
    void Draw(sf::RenderWindow &window);
    /**
     * Draw title of the game.
     * @param window
     */
    void drawTitle(sf::RenderWindow &window) ;
    /**
     * Draw each Square at the specific location with name and color at window.
     * @param i
     * @param name
     * @param color
     * @param window
     */
    void DrawSquare(int i, const std::string &name, sf::Color color, sf::RenderWindow &window);
   /**
    * Getter for the board.
    * @return
    */
    static Board * getBoard();
    /**
     * Get the index of the square based string location.
     * @param location
     * @return
     */
    int getSquareIndex(const std::string &location) const;
    std::vector<std::unique_ptr<Square>>& getSquares();
    ~Board();
    /**
     * Delete copy constructor and assignment operator.
     * Maintain Singleton Structure.
     */
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
};

#endif // MONOPOLY_BOARD_HPP
