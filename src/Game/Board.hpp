#ifndef BOARD_H_DEFINED
#define BOARD_H_DEFINED

#include <Misc/Array2D.hpp>
#include <Interface/Window.hpp>

// Avoiding circular #include hell.
class Player;

/// A level where the snake runs and eats fruits.
///
/// @note I couldn't name this class "Level" because it could
///       get confusing with the concept of game speed, which is
///       also based on the word "Level".
///
/// This class represents a single level the snake can play on.
///
/// It is essentially a 2D matrix of tiles, where each can be
/// either "Walls" or "Empty.
///
/// It also contains some extra info, like the position where
/// the player should spawn, and (if this level was created by
/// someone) the author, date and stuff.
///
class Board
{
public:
	/// If the player will teleport when reaching the
	/// Board's limits or not.
	enum Style { SOLID, TELEPORT };

	/// Creates a new Board.
	///
	/// @param width   Whole level width
	/// @param height  Whole level height
	/// @param style   If the player will teleport when reaching the limits
	/// @param start_x Player's starting position (x axis)
	/// @param start_y Player's starting position (y ayis)
	///
	Board(int width, int height, Style style, int start_x=2, int start_y=2);

	virtual ~Board();

	/// Tells if there's a wall at #x #y.
	bool isWall(int x, int y);
	bool isBorder(int x, int y);

	int getW();
	int getH();

	void draw(Window* win);

	/// Places random walls all over the Board
	/// except by #x and #y, allowing the Player
	/// to move a little bit when starting.
	void randomlyFillExceptBy(int x, int y);

	/// Makes the `Player` teleport if it's on a border.
	void teleport(Player* player);

	/// Sets the whole level content.
	///
	/// @param newBoard 2D matrix of booleans, telling if
	///                 there's a "Wall" on that tile or not.
	///
	void setBoard(std::vector<std::vector<bool> >& newBoard);

	/// Tells if the player will teleport when
	/// reaching the Board's limits or not.
	///
	/// @note The Board adapts automatically if you
	///       change this on-the-fly.
	Style style;

	int getStartX();
	int getStartY();

private:
	/// The actual level on the screen.
	/// `true` means there's a wall here.
	/// `false` means the player can walk through.
	Array2D<bool>* board;

	int start_x; ///< Where the player will start (x axis)
	int start_y; ///< Where the player will start (y axis)
};

#endif //BOARD_H_DEFINED

