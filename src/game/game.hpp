#ifndef GAME_H
#define GAME_H

#include <array>
#include <string>
#include "../pieces/pieces.hpp"

    class Game {
    private:
        int turn_counter = 0;
        std::array<int,64> intBoard = {0};
        Pieces* board[64] = {};
        std::string board_string = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    public:
        void string_to_intBoard();
        void intBoard_to_arrBoard();
        void set_board_string(const std::string& fen_string){
            board_string = fen_string;
        }
        void register_move();
        bool isWhiteTurn();
        void print_board();
        std::string get_piece();
        std::string get_move();
    
        
    };

    int string_to_pos(const std::string& string);
#endif