//
// Created by Oliver Bailey on 7/24/2025.
//

#ifndef AIMOVE_HPP
#define AIMOVE_HPP

#include <iosfwd>

#include "Piece.hpp"
#include "locators/Move.hpp"

class Move;
class Piece;

class AIMove {
public:
    Move piecePosition_;
    Move moveToMake_;
    double evaluation_ = 0;

    AIMove(const Move &piecePosition, const Move &moveToMake);

    std::string asNotation() const;

    friend std::ostream &operator<<(std::ostream &os, const AIMove &aiMove);

    static AIMove maxChoice(const std::vector<AIMove> &moves, PieceColour playerColour);

    static double maxEvaluation(const std::vector<AIMove> &moves, PieceColour playerColour);

private:
    bool isBetter(double currentBest, const PieceColour &turnColour) const;
};



#endif //AIMOVE_HPP
