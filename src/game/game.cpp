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

void Game::set_pieces(){
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
    int n = 8;
    for(int i = 0; i<64; i++){
        auto p = board[i];
        if(i>0 && i%8==0){
            std::cout<< n << "\n";
            n--;
        }
        if(p == nullptr){
                std::cout<<". ";
            }

        else{
            p -> printEmoji();
        }
    }
    std::cout<< n << "\na b c d e f g h" << std::endl;
}

std::string Game::get_move1(){
    std::string move;

    std::cout<< "What piece?";
    std::cin >> move;

    return move;
}

std::string Game::get_move2(){
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
        return count;
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

bool Game::isPiece(const int& i){
    return(board[i] != nullptr);
}

Pieces* Game::get_piece(const int& i){
    auto piece = board[i];
    return piece;
}

bool Game::isLegalMove(const int& p1, const int&p2){

           //checks if same color piece
    if(isPiece(p2) && board[p2] -> getColor() == board[p1] -> getColor()){
        std::cout << "INVALID MOVE: CANNOT CAPTURE OWN PIECE" << std::endl;
        return false;
    }
    //knight can jump over pieces
    if(board[p1] -> getType() == "Knight"){
        return true;
    }
    //checks if path is blocked
    int row1 = p1/8;
    int col1 = p1%8;
    int row2 = p2/8;
    int col2 = p2%8;
    int delta_row = row1 - row2;
    int delta_col = col1 - col2;
    int d1 = 0;
    int d2 = 0;
    int pos = p1;

    if(delta_row > 0){d1 = -8;}
    else if(delta_row < 0){d1 = +8;}

    if(delta_col > 0){d2 = -1;}
    else if(delta_col < 0){d2 = +1;}

    while(pos != p2){
        if(isPiece(pos)&& pos != p1){
            std::cout << "INVALID MOVE: PATH BLOCKED" << std::endl;
            return false;
        }
        pos += d1 + d2;
    }

    return true;

}

void Game::move_pieces(const int& p1, const int& p2){

    if(isPiece(p2) && board[p2] -> getColor() != board[p1] -> getColor()){
        delete board[p2];
    }
    board[p2] = board[p1];
    board [p1] = nullptr;
}

int Game::findKing(std::string color){
    for (int i = 0; i < 64; i++) {
        if (board[i] != nullptr &&
            board[i]->getType() == "King" &&
            board[i]->getColor() == color) {
            return i; 
            }
    }
    return -1;
}

bool Game::isCheck(std::string color){

    Pieces* piece;

    int w = findKing(color);
    for(int i = 0; i <64; i++){
        if(board[i]!= nullptr && board[i] ->getColor() != color)
        piece = board[i];
        else{continue;}
        if(piece -> isPossibleMove(i,w) && isLegalMove(i,w)){
            return true;
        }
        else{continue;}
    }
    return false;


}

bool Game::isCheckmate(std::string color){
    int king_pos;
    king_pos = findKing(color);

    Pieces* king;
    Pieces* piece;

    bool checkmate = true;

    king = board[king_pos];


    if(!king -> possibleMoves(king_pos).empty()){
        for(int i : king -> possibleMoves(king_pos)){
            if(isLegalMove(king_pos, i)&& king ->isPossibleMove(king_pos,i)){
                checkmate = false;
            }
        }
    }

    for(int i = 0; i<64; i++){
        if(board[i] != nullptr && board[i]->getColor()==color){
            piece = board[i];
        
            for(int j : piece ->possibleMoves(i)){
                if(isLegalMove(i,j)&& piece ->isPossibleMove(i,j)){
                    auto temp = board[j];
                    board[j] = board[i];
                    board[i] = nullptr;
                    if(!isCheck(color)){
                        checkmate = false;
                    }
                    board[i] = board[j];
                    board[j] = temp;
                }
                else{continue;}

            }
        }
        else{continue;}
    }
    return checkmate;
}

bool Game::isDraw(){

}