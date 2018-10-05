#include <utility>

#include "Piece.h"

Piece::Piece(std::vector<KeyFrame> frames) : m_frames(std::move(frames)) {
    it = 0;
}

size_t Piece::getFrameCount() {
    return m_frames.size();
}

KeyFrame Piece::step() {
    return m_frames.at(it++);
}

