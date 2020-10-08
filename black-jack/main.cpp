#include <vector>
#include <climits>

using namespace std;

// C++ defination
enum Suit {Club, Diamond, Heart, Spade};

template<class T>
class Deck {
public:
    void setDeckOfCards(vector<T> deckOfCards) {}; // ... 
    void shuffle() {}; // ... 
    int remainingCards() {
        return _cards.size() - _dealtIndex;
    }
    vector<T> dealHead(int number) {}; // ... 
    T dealCard() {}; // ... 
private:
    vector<T> _cards;
    int _dealtIndex = 0;
};

class Card {
public:
    Card(int c, Suit s): _faceValue(c), _suit(s) {};
    virtual int value() = 0;
    Suit suit() { return _suit; };
    bool isAvailable() { return _available; };
    void markUnavailable() { _available = false; };
    void markAvailable() { _available = true; };
protected:
    int _faceValue;
    Suit _suit;
private:
    bool _available = true;
};

template<class T>
class Hand {
public:
    int score() {
        int score = 0;
        for (T card : cards) {
            score += card.value();
        }
        return score;
    }
    void addCard(T card) {
        cards.add(card);
    }
protected:
    vector<T> cards;
};

class BlackJackCard: public Card {
public:
    BlackJackCard(int c, Suit s): Card(c,s) {};
    int value() {
        if (isAce()) return 1;
        else if (_faceValue >= 11 && _faceValue <= 13) return 10;
        else return _faceValue;
    }
    int minValue() {
        if (isAce()) return 1;
        else return value();
    }
    int maxValue() {
        if (isAce()) return 11;
        else return value();
    }
    bool isAce() {
        return _faceValue == 1;
    }
    bool isFaceCard() {
        return _faceValue >= 11 && _faceValue <= 13;
    }
};

class BlackjackHand: public Hand<BlackJackCard> {
public:
    int score() {
        vector<int> scores = possibleScores();
        int maxUnder = INT_MIN, minOver = INT_MAX;
        for (auto a : scores) {
            if (a > 21 && a < minOver) {
                minOver = a;
            } else if (a <= 21 && a > maxUnder) {
                maxUnder = a;
            }
        }
        return maxUnder == INT_MIN ? minOver : maxUnder;
    }
    bool busted() { return score() > 21; };
    bool is21() { return score() == 21; };
    bool isBlackJack() {}; // ...
private:
    vector<int> possibleScores() {}; // ...
};