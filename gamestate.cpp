// Includes I didn't make myself


// Includes I did make myself
#include "gamestate.hpp"
#include "gsGame.hpp"
#include "gsMenu.hpp"

cGameMan::cGameMan(GameStates startState) {
    switch (startState) {
        case STATE_GAME:
            this->currState = new gsGame();
            break;
        case STATE_MENU:
            this->currState = new gsMenu();
            break;
        default:
            this->currState = new gsMenu();
            break;
    }

    this->stateID = startState;
    this->nextState = STATE_NULL;

    diff = 2;
    snd = true;
}

cGameMan::~cGameMan() {
    delete this->currState;
}

int cGameMan::setNextState(GameStates targetState) {
    if (this->nextState != STATE_EXIT) {
        this->nextState = targetState;
    }

    return 0;
}

int cGameMan::changeState() {
    if (this->nextState != STATE_NULL) {
        if (this->nextState != STATE_EXIT) {
            delete this->currState;

            switch (this->nextState) {
                case STATE_GAME:
                    this->currState = new gsGame();
                    break;
                case STATE_MENU:
                    this->currState = new gsMenu();
                    break;
                default:
                    this->currState = new gsMenu();
                    break;
            }

            this->stateID = this->nextState;
            this->nextState = STATE_NULL;
        } else {
            this->stateID = STATE_EXIT;
        }
    }

    return 0;
}

GameStates cGameMan::getState() {
    return this->stateID;
}