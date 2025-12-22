#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <vector>

class Pieces{
    protected:
        std::string color;
    
    public:
         Pieces(const std::string c) : color(c){};
         const std::string getColor() { return color; }
         bool isPossibleMove(const int& pos1, const int& pos2);
         virtual std::vector<int> possibleMoves(const int& pos) = 0;
         virtual void printEmoji() = 0;
         virtual std::string getType() = 0;
         virtual ~Pieces() = default;

};

class Pawn : public Pieces{
    public:
        Pawn(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
        std::string getType() override { return "Pawn"; }
};

class Rook : public Pieces{
    public:
        Rook(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
        std::string getType() override { return "Rook"; }
};

class Knight : public Pieces{
    public:
        Knight(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
        std::string getType() override { return "Knight"; }
};

class Bishop : public Pieces{
    public:
        Bishop(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
        std::string getType() override { return "Bishop"; }
};

class Queen : public Pieces{
    public:
        Queen(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override; 
        std::string getType() override { return "Queen"; }
};

class King : public Pieces{
    public:
        King(const std::string c) : Pieces(c){};
        std::vector<int> possibleMoves(const int& pos) override;
        void printEmoji() override;
        std::string getType() override { return "King"; }
};









#endif 