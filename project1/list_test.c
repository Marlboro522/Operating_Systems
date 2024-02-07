#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <errno.h>                     
int main() {
   list *my_list= create_list();
    add_to_list(my_list,"Node 1");
    add_to_list(my_list,"Node 2");
    add_to_list(my_list,"Node 3");
    add_to_list(my_list,"Node 4");
    add_to_list(my_list,"Node 5");
    print_list(my_list);
    remove_from_list(my_list);
    remove_from_list(my_list);
    remove_from_list(my_list);
    print_list(my_list);
    flush_list(my_list);
    print_list(my_list);
    add_to_list(my_list,"Node 1");
    add_to_list(my_list,"Node 2");
    add_to_list(my_list,"Node 3");
    add_to_list(my_list,"Node 4");
    add_to_list(my_list,"Node 5");
    print_list(my_list);
    free_list(&my_list);

}
