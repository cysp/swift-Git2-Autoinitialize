//#include <git2/git2.h>
//#import <CGit2/CGit2.h>

extern int git_libgit2_init(void);
extern int git_libgit2_shutdown(void);

__attribute__((constructor))
static void Git2Initialize(void) {
    git_libgit2_init();
}

__attribute__((destructor))
static void Git2Shutdown(void) {
    git_libgit2_shutdown();
}
