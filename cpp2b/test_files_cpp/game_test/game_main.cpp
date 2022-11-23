#include "controller.h"
#include "console.h"

int main(){

Controller controller("Playstation controller");
controller.declare_parts_ctrl();
controller.print_controller();

Console console;
console.declare_parts_cons();
console.print_console();

return 0;
};