#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"
#include "ui.h"

class Controller {

public:
    void run();

private:
    FruitRepository repository;
    FruitUI ui;
};

#endif // CONTROLLER_H
