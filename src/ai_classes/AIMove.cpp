//
// Created by Oliver Bailey on 7/24/2025.
//

#include "ai_classes/AIMove.hpp"

#include "Piece.hpp"

AIMove::AIMove(const Move &piecePosition, const Move &moveToMake)
    : piecePosition_(piecePosition), moveToMake_(Move::copy(moveToMake)) {}

// std::string AIMove::asNotation() const {
//     std::string thing = piece_->getPiecePosition().getNotation() + moveToMake_.getNotation();
//
//     if (moveToMake_.isPromotion()) {
//         thing += moveToMake_.getPromotionLetter();
//     }
//
//     return thing;
// }

AIMove AIMove::maxChoice(const std::vector<AIMove> &moves, const PieceColour playerColour) {
    double maxEvaluation = moves[0].evaluation_;
    int bestMoveIndex = 0;

    for (int i = 1; i < moves.size(); ++i) {
        if (moves[i].isBetter(maxEvaluation, playerColour)) {
            maxEvaluation = moves[i].evaluation_;
            bestMoveIndex = i;
    }}

    return moves[bestMoveIndex];
}

double AIMove::maxEvaluation(const std::vector<AIMove> &moves, const PieceColour playerColour) {
    double maxEvaluation = moves[0].evaluation_;

    for (const AIMove &move : moves) {
        if (move.isBetter(maxEvaluation, playerColour)) {
            maxEvaluation = move.evaluation_;
    }}

    return maxEvaluation;
}


// std::ostream &operator<<(std::ostream &os, const AIMove &aiMove) {
//     return os << aiMove.piece_->getPieceType() << " " << aiMove.piece_->getPiecePosition() << ": " << aiMove.moveToMake_;
// }

bool AIMove::isBetter(const double currentBest, const PieceColour &turnColour) const {
    if (turnColour == PieceColour::White)
        return currentBest < evaluation_;
    else
        return currentBest > evaluation_;
}
