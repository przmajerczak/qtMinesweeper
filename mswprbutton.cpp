#include "mswprbutton.h"

MswprButton::MswprButton(QWidget* parent, int _x_id, int _y_id, bool is_bomb) : QPushButton(parent) {
    this->id_x = _x_id;
    this->id_y = _y_id;
    this->is_covered = true;
    this->state = is_bomb ? bomb : empty;
    this->neighbouring_bombs = 0;
}

int MswprButton::getX() {
    return this->id_x;
}

int MswprButton::getY() {
    return this->id_y;
}

void MswprButton::setState(mswprBtn_state _stt) {
    this->state = _stt;
    switch (this->state) {
    case 0:
        this->setText("_");
        break;
    case 9:
        this->setText("B");
        break;
    default:
        this->setText(QString::number(this->state));
    }
}

mswprBtn_state MswprButton::getState() {
    return this->state;
}

void MswprButton::increaseBombsCount() {
    neighbouring_bombs++;
    this->setText(QString::number(neighbouring_bombs));
}
