#ifndef MY_KALLSYMS_H
#define MY_KALLSYMS_H

#include <linux/kprobes.h>

typedef void* (*kallsyms_lookup_name_t)(const char *name);
extern kallsyms_lookup_name_t my_kallsyms_lookup_name;

extern long int init_my_kallsyms(void);

#endif //MY_KALLSYMS_H
