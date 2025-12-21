#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <vector>

class Pieces{
    protected:
        std::string color;
    
    public:
         Pieces(const std::string c) : color(c){};
         bool isWhite();
         int string_to_pos(const std::string& string);
         bool isPossibleMove(const std::string& string);
         virtual std::vector<int> possibleMoves(const int& pos) = 0;
         virtual void printEmoji() = 0;
         virtual ~Pieces() = default;

};

class Pawn : public Pieces{
    public:
        Pawn(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;

};

class Rook : public Pieces{
    public:
        Rook(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
};

class Knight : public Pieces{
    public:
        Knight(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
};

class Bishop : public Pieces{
    public:
        Bishop(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
};

class Queen : public Pieces{
    public:
        Queen(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override; 
};

class King : public Pieces{
    public:
        King(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
};









#endif 