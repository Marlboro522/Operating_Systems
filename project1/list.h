// Forward declaration of the structure: Node
typedef struct Node node;
typedef struct List list;
// Definition of the structure Node
struct Node {
    char *item;
    node *next;
};

// Definition of the structure: List
struct List {
    node *head;
};

// Function prototypes
list* create_list();
int add_to_list(list *ll, char *item);
char *remove_from_list(list *ll);
void print_list(list *ll);
void flush_list(list *ll);
void free_list(list **ll);
