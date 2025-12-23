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
        void set_pieces();
        void set_board_string(const std::string& fen_string){
            board_string = fen_string;
        }
        void register_move();
        bool isWhiteTurn();
        void print_board();
        std::string get_move1();
        std::string get_move2();
        int string_to_pos(const std::string& string);
        bool isPiece(const int& pos);
        Pieces* get_piece(const int& pos);
        bool isLegalMove(const int& p1, const int& p2);
        void move_pieces(const int& i, const int& j);
        int findKing(std::string color);
        bool isCheck(std::string color);
        bool isCheckmate(std::string color);
        bool isDraw();

        
    };

#endif