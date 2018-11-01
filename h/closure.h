#define list_size(list) (sizeof(list.list) / sizeof(int))

typedef int size_r;

struct list_struct {
    int size;
    int *list;
};

struct _closure {
    double first_arg;
    double (*call)(struct _closure *closure, double value);
};

typedef struct _closure Closure;

typedef struct list_struct List;

