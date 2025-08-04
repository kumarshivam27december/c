#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

using namespace std;

// --------------------------- Enums ---------------------------

enum class PieceColor { WHITE, BLACK };
enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

// --------------------------- Strategy Pattern ---------------------------

class MoveStrategy {
public:
    virtual bool isValidMove(int sx, int sy, int dx, int dy) = 0;
    virtual ~MoveStrategy() = default;
};

class RookStrategy : public MoveStrategy {
public:
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        return sx == dx || sy == dy;
    }
};

class BishopStrategy : public MoveStrategy {
public:
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        return abs(sx - dx) == abs(sy - dy);
    }
};

class QueenStrategy : public MoveStrategy {
public:
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        return RookStrategy().isValidMove(sx, sy, dx, dy) || BishopStrategy().isValidMove(sx, sy, dx, dy);
    }
};

class KnightStrategy : public MoveStrategy {
public:
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        int dx_ = abs(sx - dx);
        int dy_ = abs(sy - dy);
        return (dx_ == 2 && dy_ == 1) || (dx_ == 1 && dy_ == 2);
    }
};

class KingStrategy : public MoveStrategy {
public:
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        return abs(sx - dx) <= 1 && abs(sy - dy) <= 1;
    }
};

class PawnStrategy : public MoveStrategy {
    PieceColor color;
public:
    PawnStrategy(PieceColor c) : color(c) {}
    bool isValidMove(int sx, int sy, int dx, int dy) override {
        int dir = (color == PieceColor::WHITE) ? -1 : 1;
        return (dx - sx == dir && sy == dy); // No captures or first-move double-step here
    }
};

// --------------------------- Piece Base ---------------------------

class Piece {
protected:
    PieceColor color;
    PieceType type;
    unique_ptr<MoveStrategy> strategy;

public:
    Piece(PieceColor c, PieceType t, unique_ptr<MoveStrategy> s) : color(c), type(t), strategy(move(s)) {}
    virtual ~Piece() = default;

    PieceColor getColor() const { return color; }
    PieceType getType() const { return type; }

    bool isValidMove(int sx, int sy, int dx, int dy) {
        return strategy->isValidMove(sx, sy, dx, dy);
    }

    virtual string name() const = 0;
};

class Rook : public Piece {
public:
    Rook(PieceColor c) : Piece(c, PieceType::ROOK, make_unique<RookStrategy>()) {}
    string name() const override { return "R"; }
};

class Bishop : public Piece {
public:
    Bishop(PieceColor c) : Piece(c, PieceType::BISHOP, make_unique<BishopStrategy>()) {}
    string name() const override { return "B"; }
};

class Queen : public Piece {
public:
    Queen(PieceColor c) : Piece(c, PieceType::QUEEN, make_unique<QueenStrategy>()) {}
    string name() const override { return "Q"; }
};

class Knight : public Piece {
public:
    Knight(PieceColor c) : Piece(c, PieceType::KNIGHT, make_unique<KnightStrategy>()) {}
    string name() const override { return "N"; }
};

class King : public Piece {
public:
    King(PieceColor c) : Piece(c, PieceType::KING, make_unique<KingStrategy>()) {}
    string name() const override { return "K"; }
};

class Pawn : public Piece {
public:
    Pawn(PieceColor c) : Piece(c, PieceType::PAWN, make_unique<PawnStrategy>(c)) {}
    string name() const override { return "P"; }
};

// --------------------------- Factory Pattern ---------------------------

class PieceFactory {
public:
    static shared_ptr<Piece> createPiece(PieceType type, PieceColor color) {
        switch (type) {
            case PieceType::ROOK: return make_shared<Rook>(color);
            case PieceType::BISHOP: return make_shared<Bishop>(color);
            case PieceType::QUEEN: return make_shared<Queen>(color);
            case PieceType::KNIGHT: return make_shared<Knight>(color);
            case PieceType::KING: return make_shared<King>(color);
            case PieceType::PAWN: return make_shared<Pawn>(color);
        }
        return nullptr;
    }
};

// --------------------------- Board (Composite Style) ---------------------------

class Square {
    shared_ptr<Piece> piece;

public:
    void setPiece(shared_ptr<Piece> p) { piece = p; }
    shared_ptr<Piece> getPiece() const { return piece; }
    void clear() { piece = nullptr; }

    bool isEmpty() const { return piece == nullptr; }
};

class Board {
    vector<vector<Square>> grid;

public:
    Board() : grid(8, vector<Square>(8)) {}

    void placePiece(int x, int y, shared_ptr<Piece> piece) {
        grid[x][y].setPiece(piece);
    }

    bool movePiece(int sx, int sy, int dx, int dy) {
        auto piece = grid[sx][sy].getPiece();
        if (!piece || !piece->isValidMove(sx, sy, dx, dy)) return false;

        grid[dx][dy].setPiece(piece);
        grid[sx][sy].clear();
        return true;
    }

    void print() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                auto p = grid[i][j].getPiece();
                if (p) {
                    cout << (p->getColor() == PieceColor::WHITE ? 'W' : 'B') << p->name() << " ";
                } else {
                    cout << "-- ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

// --------------------------- Singleton Pattern ---------------------------

class GameManager {
    static GameManager* instance;
    Board board;

    GameManager() { initBoard(); }

    void initBoard() {
        // Simplified: only placing some pieces
        board.placePiece(0, 0, PieceFactory::createPiece(PieceType::ROOK, PieceColor::WHITE));
        board.placePiece(0, 1, PieceFactory::createPiece(PieceType::KNIGHT, PieceColor::WHITE));
        board.placePiece(0, 2, PieceFactory::createPiece(PieceType::BISHOP, PieceColor::WHITE));
        board.placePiece(0, 3, PieceFactory::createPiece(PieceType::QUEEN, PieceColor::WHITE));
        board.placePiece(0, 4, PieceFactory::createPiece(PieceType::KING, PieceColor::WHITE));

        board.placePiece(7, 0, PieceFactory::createPiece(PieceType::ROOK, PieceColor::BLACK));
        board.placePiece(7, 1, PieceFactory::createPiece(PieceType::KNIGHT, PieceColor::BLACK));
        board.placePiece(7, 2, PieceFactory::createPiece(PieceType::BISHOP, PieceColor::BLACK));
        board.placePiece(7, 3, PieceFactory::createPiece(PieceType::QUEEN, PieceColor::BLACK));
        board.placePiece(7, 4, PieceFactory::createPiece(PieceType::KING, PieceColor::BLACK));
    }

public:
    static GameManager* getInstance() {
        if (!instance) instance = new GameManager();
        return instance;
    }

    void printBoard() { board.print(); }

    void move(int sx, int sy, int dx, int dy) {
        if (board.movePiece(sx, sy, dx, dy)) {
            cout << "Move successful\n";
        } else {
            cout << "Invalid move\n";
        }
    }
};

GameManager* GameManager::instance = nullptr;

// --------------------------- Main ---------------------------

int main() {
    GameManager* game = GameManager::getInstance();
    game->printBoard();

    game->move(0, 0, 0, 5);  // Rook move
    game->move(0, 1, 2, 2);  // Knight move

    game->printBoard();
    return 0;
}
