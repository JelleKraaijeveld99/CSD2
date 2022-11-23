#include "controller.h"

int main(){

Controller controller("Playstation controller");
controller.declare_parts_ctrl();
controller.print_controller();

return 0;
};