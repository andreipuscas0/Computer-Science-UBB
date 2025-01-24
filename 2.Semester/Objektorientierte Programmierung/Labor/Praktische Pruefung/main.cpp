#include "Repository.h"
#include "Controller.h"
#include "Test.h"
#include "UI.h"

int main() {
    MedicationRepository repository;
    MedicationController controller(repository);
    UI ui(controller);
    runTests();
    ui.displayMenu();

    return 0;
}
