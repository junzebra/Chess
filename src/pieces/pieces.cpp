#include "pieces.hpp"

#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../game/game.hpp"


bool Pieces::isPossibleMove(const int& pos1, const int& pos2){
 

    if (pos2 == 100){
        return false;
    }

    //checks to see if in possibleMoves vector
    std::vector<int> moves = possibleMoves(pos1);
    std::vector<int>::iterator it = std::find(moves.begin(),moves.end(),pos2);

    if(it != moves.end()){
        return true;
    }
    else{
        return false;
    }
}



void Pawn::printEmoji(){
    if (color == "White"){
        std::cout << "♟ ";
    }
    else{
        std::cout << "♙ ";
    }
}

void Rook::printEmoji(){
    if (color == "White"){
        std::cout << "♜ ";
    }
    else{
        std::cout << "♖ ";
    }
}

void Bishop::printEmoji(){
    if (color == "White"){
        std::cout << "♝ ";
    }
    else{
        std::cout << "♗ ";
    }
}

void Knight::printEmoji(){
    if (color == "White"){
        std::cout << "♞ ";
    }
    else{
        std::cout << "♘ ";
    }
}

void Queen::printEmoji(){
    if (color == "White"){
        std::cout << "♛ ";
    }
    else{
        std::cout << "♕ ";
    }
}

void King::printEmoji(){
    if (color == "White"){
        std::cout << "♚ ";
    }
    else{
        std::cout << "♔ ";
    }
}

std::vector<int> Pawn::possibleMoves(const int& pos) { 
    std::vector<int> moves;
        if(color=="White"){
            if(pos-8 >= 0)
            moves.push_back(pos-8);
            if(pos >= 48 && pos < 56 && pos-8){
                moves.push_back(pos-16);
            }

        }
        else{
            if(pos+8 < 64)
            moves.push_back(pos+8);
            if(pos >= 8 && pos < 16){
                moves.push_back(pos+16);
            }

        }

    return moves; 
}

std::vector<int> Rook::possibleMoves(const int& pos) {
    std::vector<int> moves;
    int mod = pos%8;
    int rest = 7-mod;
    for (int i = 0;i < 64; i++){
        //the vertical
        if (mod == i%8 && i != pos){
            moves.push_back(i);
        }
        //the horizontal
        if (i>= pos - mod && i <= pos + (8 - mod) && i != pos){
            moves.push_back(i);
        }
    }

    return moves; 
}

std::vector<int> Knight::possibleMoves(const int& pos) {
    std::vector<int> moves;
    int mod = pos%8;

    //only pushes if in expected column
    if(((pos-17)%8 == mod-1 && pos-17 >= 0))
    moves.push_back(pos-17);
    if(((pos-15)%8 == mod+1 && pos-15 >= 0))
    moves.push_back(pos-15);
    if(((pos-10)%8 == mod-2 && pos-10 >= 0))
    moves.push_back(pos-10);
    if(((pos-7)%8 == mod+2 && pos-7 >= 0))
    moves.push_back(pos-7);
    if(((pos+6)%8 == mod-2 && pos+6 < 64))
    moves.push_back(pos+6);
    if(((pos+10)%8 == mod+2 && pos+10 < 64))
    moves.push_back(pos+10);
    if(((pos+15)%8 == mod-1 && pos+15 < 64))
    moves.push_back(pos+15);
    if(((pos+17)%8 == mod+1 && pos+17  < 64))
    moves.push_back(pos+17);

    return moves; 
}
std::vector<int> Bishop::possibleMoves(const int& pos) {
    std::vector<int> moves;
    int mod = pos%8;
    int increment = 9;

    //pushes diagonals ignoring initial pos
    for(int n = 1; n <9;n++){
        if(((pos+(n*increment))%8 == mod+n) && pos+(n*increment) < 64){
            moves.push_back(pos+(n*increment));
        }
        if(((pos-(n*increment))%8 == mod-n) && pos-(n*increment) >= 0){
            moves.push_back(pos-(n*increment));
        }
    }

    return moves; 
}
std::vector<int> Queen::possibleMoves(const int& pos) {
    std::vector<int> moves;
    int mod = pos&8;
    int increment = 9;

     for (int i = 0;i < 64; i++){
        //the vertical
        if (mod == i%8 && i != pos){
            moves.push_back(i);
        }
        //the horizontal
        if (i>= pos - mod && i <= pos + (8 - mod) && i != pos){
            moves.push_back(i);
        }
    }

    //pushes diagonals ignoring initial pos
    for(int n = 1; n <9;n++){
        if(((pos+(n*increment))%8 == mod+n) && pos+(n*increment) < 64){
            moves.push_back(pos+(n*increment));
        }
        if(((pos-(n*increment))%8 == mod-n) && pos-(n*increment) >= 0){
            moves.push_back(pos-(n*increment));
        }
    }

    return moves; 
}
std::vector<int> King::possibleMoves(const int& pos) {
    std::vector<int> moves;
    int mod = pos%8;

    if(((pos-9)%8 == mod-1) && pos-9 >= 0)
    moves.push_back(pos-9);
    if(((pos-8)%8 == mod) && pos-8 >= 0)
    moves.push_back(pos-8);
    if(((pos-7)%8 == mod+1) && pos-7 >= 0)
    moves.push_back(pos-7);
    if(((pos-1)%8 == mod-1) && pos-1 >= 0)
    moves.push_back(pos-1);
    if(((pos+1)%8 == mod+1) && pos+1 < 64)
    moves.push_back(pos+1);
    if(((pos+7)%8 == mod-1) && pos+7 < 64)
    moves.push_back(pos+7);
    if(((pos+8)%8 == mod) && pos+8 < 64)
    moves.push_back(pos+8);
    if(((pos+9)%9 == mod+1) && pos+9 < 64)
    moves.push_back(pos+9);


    return moves; 
}
