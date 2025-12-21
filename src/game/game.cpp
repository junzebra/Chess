#include "game.hpp"

#include <string>
#include <array>
#include <iostream>

//Converts a FEN string to an arr[64]
void Game::string_to_intBoard(){
    int pos = 0;
    for (char c : board_string){
        if(c >= '1' && c <= '8'){
            int pos_skip = c - '0';
            pos += pos_skip;
        }
        //ignore the '/'
        else if(c == '/'){
            continue;
        }
        else{
            intBoard[pos] = c;
            pos++;
        }
    }
}

void Game::intBoard_to_arrBoard(){
    for (int i = 0; i < 64 ; i++){
        int piece = intBoard[i];
        if (piece == 0){
            board[i] = nullptr;
        }
        else if (piece == 'P'){board[i] = new Pawn("White");}
        else if (piece == 'p'){board[i] = new Pawn("Black");}
        else if (piece == 'R'){board[i] = new Rook("White");}
        else if (piece == 'r'){board[i] = new Rook("Black");}
        else if (piece == 'N'){board[i] = new Knight("White");}
        else if (piece == 'n'){board[i] = new Knight("Black");}
        else if (piece == 'B'){board[i] = new Bishop("White");}
        else if (piece == 'b'){board[i] = new Bishop("Black");}
        else if (piece == 'Q'){board[i] = new Queen("White");}
        else if (piece == 'q'){board[i] = new Queen("Black");}
        else if (piece == 'K'){board[i] = new King("White");}
        else if (piece == 'k'){board[i] = new King("Black");}
    }
}

void Game::register_move(){
    turn_counter++;
}

bool Game::isWhiteTurn(){
    if(turn_counter%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

void Game::print_board(){
    for(int i = 0; i<64; i++){
        auto p = board[i];
        if(i>0 && i%8==0){
            std::cout<<"\n";
        }
        if(p == nullptr){
                std::cout<<". ";
            }

        else{
            p -> printEmoji();
        }
    }
    std::cout<<std::endl;
}

std::string Game::get_piece(){
    std::string move;

    std::cout<< "What piece?";
    std::cin >> move;

    return move;
}

std::string Game::get_move(){
    std::string move;

    std::cout<< "Where to?";
    std::cin >> move;

    return move;
}

int Game::string_to_pos(const std::string& string){

    if (string.length() != 2){
        std::cout << "INVALID MOVE" << std::endl;
        return 100;
    }

    int count = 0;

        //parsing the letter 
    if (string[0] == 'a'){
        count = 0;
    }
    else if (string[0] == 'b'){
        count = 1;
    }
    else if (string[0] == 'c'){
        count = 2;
    }
    else if (string[0] == 'd'){
        count = 3;
    }
    else if (string[0] == 'e'){
        count = 4;
    }
    else if (string[0] == 'f'){
        count = 5;
    }
    else if (string[0] == 'g'){
        count = 6;
    }
    else if (string[0] == 'h'){
        count = 7;
    }
    else{
        std::cout << "NOT A VALID MOVE";
        return 100;
    }

    //parsing the number
    if (string[1] == '8'){return count;}
    else if (string[1] == '7'){
        count += 8;
    }
    else if (string[1] == '6'){
        count += 16;
        return count;
    }
    else if (string[1] == '5'){
        count += 24;
        return count;
    }
    else if (string[1] == '4'){
        count += 32;
        return count;
    }
    else if (string[1] == '3'){
        count += 40;
        return count;
    }
    else if (string[1] == '2'){
        count += 48;
        return count;
    }
    else if (string[1] == '1'){
        count += 56;
        return count;
    }
    else{
        std::cout << "NOT A VALID MOVE";
        return 100;
    }
return 0;
}

