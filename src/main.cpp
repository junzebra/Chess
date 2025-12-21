#include "game/game.hpp"
#include "pieces/pieces.hpp"
#include <iostream>



int main() {


    Game myGame;

    myGame.string_to_intBoard();
    myGame.intBoard_to_arrBoard();

    // 4. Print the result
    std::cout << "Starting Board State:\n" << std::endl;
    myGame.print_board();

    std::string piece = myGame.get_piece();
    std::string move = myGame.get_move();

    int piece_pos = Piece::string_to_pos(piece);


    return 0;
}
