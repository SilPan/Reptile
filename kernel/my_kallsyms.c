#ifndef MY_KALLSYMS_H
#define MY_KALLSYMS_H

#include <linux/kprobes.h>

#include "my_kallsyms.h"

kallsyms_lookup_name_t my_kallsyms_lookup_name;

long int init_my_kallsyms(void){
    static struct kprobe kp = {
        .symbol_name = "kallsyms_lookup_name"
    };
    register_kprobe(&kp);
    my_kallsyms_lookup_name = (kallsyms_lookup_name_t) kp.addr;
    unregister_kprobe(&kp);

    return my_kallsyms_lookup_name != NULL;
}
#endif //MY_KALLSYMS_H

