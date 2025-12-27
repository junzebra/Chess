#include "game/game.hpp"
#include "pieces/pieces.hpp"
#include <iostream>
#include <stdlib.h>



int main() {

    //sets initial game state
    Game myGame;
    myGame.string_to_intBoard();
    myGame.set_pieces();

    // Print the result
    std::cout << "Starting Board State:\n" << std::endl;
    myGame.print_board();

    //Main loop
    for(int turn = 0; turn < 100; turn++){
        std::string piece = myGame.get_move1();
        std::string move = myGame.get_move2();
        int pos1 = myGame.string_to_pos(piece);
        int pos2 = myGame.string_to_pos(move);

        Pieces* piece1 = myGame.get_piece(pos1);
        if(piece1 == nullptr){
            std::cout << "NO PIECE AT SELECTED POSITION" << std::endl;
            continue;
        }
        if(!myGame.isWhiteTurn() && piece1 ->getColor() == ("White")){
            std::cout << "NOT WHITES TURN" << std::endl;
            continue;
        }
        if(myGame.isWhiteTurn() && piece1 ->getColor() == ("Black")){
            std::cout << "NOT BLACKS TURN" << std::endl;
            continue;
        }
        if(piece1 -> isPossibleMove(pos1, pos2) && myGame.isLegalMove(pos1, pos2)){
            if(!myGame.isSafeMove(pos1, pos2, piece1->getColor())){
                std::cout << "INVALID MOVE: KING IN CHECK" << std::endl;
                continue;
            }
            myGame.move_pieces(pos1, pos2);
            system("clear");
            if(myGame.isCheck("White")){
                if(myGame.isCheckmate("White"))
                std::cout<<"BLACK WINS!\n";
                else
                std::cout<<"Check!!\n";
            }
            if(myGame.isCheck("Black")){
                if(myGame.isCheckmate("Black"))
                std::cout<<"WHITE Wins!\n";
                else
                std::cout<<"Check!!\n";
            }
            
            myGame.print_board();
            myGame.register_move();
            }
     }
    return 0;
}
