#ifndef DBGHELP_SYMINIT_MANAGER_HPP
#define DBGHELP_SYMINIT_MANAGER_HPP

#include <unordered_map>

namespace cpptrace {
namespace detail {
    struct dbghelp_syminit_manager {
        // The set below contains Windows `HANDLE` objects, `void*` is used to avoid 
        // including the (expensive) Windows header here
        std::unordered_map<void*, void*> cache;

        ~dbghelp_syminit_manager();
        void* init(void* proc);
    };

    // Thread-safety: Must only be called from symbols_with_dbghelp while the dbghelp_lock lock is held
    dbghelp_syminit_manager& get_syminit_manager();
}
}

#endif
