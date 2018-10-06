#include <utility>

#include <utility>

#pragma once

#include <unordered_map>
#include <memory>
#include "Piece.h"

class PieceStorage {
public:
    static PieceStorage& get() {
        static PieceStorage storage;
        return storage;
    }
protected:
    std::unordered_map<std::string, Piece> m_pieces;
public:
    void store(const std::string &s, Piece p) {
        PieceStorage::m_pieces[s] = std::move(p);
    }
    Piece& getPiece(const std::string &s) {
        return PieceStorage::m_pieces.at(s);
    }
};

