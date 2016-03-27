extern void * dlsym(void * __handle, const char * __symbol);
#define RTLD_DEFAULT    ((void *) -2)   /* Use default search algorithm. */

typedef int(*git_libgit2_init_f)(void);
typedef int(*git_libgit2_shutdown_f)(void);

__attribute__((constructor))
static void Git2AutoinitializeInitialize(void) {
    git_libgit2_init_f const git_libgit2_init = dlsym(RTLD_DEFAULT, "git_libgit2_init");
    if (git_libgit2_init) {
        git_libgit2_init();
    }
}

__attribute__((destructor))
static void Git2AutoinitializeShutdown(void) {
    git_libgit2_shutdown_f const git_libgit2_shutdown = dlsym(RTLD_DEFAULT, "git_libgit2_shutdown");
    if (git_libgit2_shutdown) {
        git_libgit2_shutdown();
    }
}
