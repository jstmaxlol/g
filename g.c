#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  g - the git wrapper
 *      $version_number
 */


//                             mm-dd.vvv
//                             with:
//                             mm  -> month
//                             dd  -> day
//                             vvv -> continous version number
const char version_number[] = "11-18.001";
const char red[] = "\033[31m";
const char def[] = "\033[0m";

char strn1[2048]; // arg buffer 1
char strn2[2048]; // arg buffer 2

void usage();

int main(int argc, char **argv) {
    /*
     *  the structure is:
     *  if (n. of argc)
     *  — options with that n. of argc
     *  else if (another n. of argc)
     *  — options with that other n. of argc
     *  and so on and so forth.
     *  sorry
     */
    if (argc == 2) {
        strcpy(strn1, argv[1]);
        if (strcmp(strn1, "i") == 0 || strcmp(strn1, "in") == 0 ||
            strcmp(strn1, "ini") == 0 || strcmp(strn1, "init") == 0) {
            system("git init");
            return 0;
        } else if (strcmp(strn1, "s") == 0 || strcmp(strn1, "st") == 0 ||
                   strcmp(strn1, "sta") == 0 || strcmp(strn1, "stat") == 0 ||
                   strcmp(strn1, "statu") == 0 || strcmp(strn1, "status") == 0) {
            system("git status");
            return 0;
        } else if (strcmp(strn1, "d") == 0 || strcmp(strn1, "di") == 0 ||
                   strcmp(strn1, "dif") == 0 || strcmp(strn1, "diff") == 0) {
            system("git diff");
            return 0;
        } else if (strcmp(strn1, "c") == 0 || strcmp(strn1, "co") == 0 ||
                   strcmp(strn1, "com") == 0 || strcmp(strn1, "comm") == 0 ||
                   strcmp(strn1, "commi") == 0 || strcmp(strn1, "commit") == 0) {
            system("git commit");
            return 0;
        } else if (strcmp(strn1, "h") == 0 || strcmp(strn1, "he") == 0 ||
                   strcmp(strn1, "hel") == 0 || strcmp(strn1, "help") == 0) {
            usage();
            return 0;
        }
                   
    }

    usage();
    return 0;
}

void usage() {
    printf(
        "%sg%s - the %sgit%s wrapper\n"
        "spinning version %s%s%s\n"
        "==============================================================\n"
        "generally: 'g [%sstuff%s]', got it?\n"
        "[] -> %soptional%s\n"
        "{} -> %srequired%s\n"
        "==============================================================\n"
        "stuff;\n"
        "g %si%s [path]                     -> git init [path]\n"
        "g %ss%s                            -> git status\n"
        "g %sd%s [s] [commit1 commit2]      -> git diff [--staged] [commit1 commit2]\n"
        "g %sc%s [a] [m {\"msg\"}]            -> git commit [-a] [-m {\"msg\"}]\n"
        "g %sf%s [remote [branch]]          -> git fetch [remote [branch]]\n"
        "g %sm%s [branch]                   -> git merge [branch]\n"
        "g %spl%s [r]                       -> git pull [--rebase]\n"
        "g %sps%s [u] [remote [branch|tag]] -> git push [-u] [remote [branch|tag]]\n"
        "g %sl%s [o] [number]               -> git log [--oneline] [-n {number}]\n"
        "g %sst%s [p|l]                     -> git stash [pop|list]\n"
        "g %sh%s                            -> prints this usage screen\n"
        "==============================================================\n"
        "g %sg%s {url} [folder]             -> git clone {url} [folder]\n"
        "g %sa%s {file | a}                 -> git add {file | -A}\n"
        "g %sb%s [d] {name}                 -> git branch [-d] {name}\n"
        "g %ssw%s [c] {branch}              -> git switch [-c] {branch}\n"
        "g %sco%s {commit}                  -> git checkout {commit}\n"
        "g %sre%s [s] {file}                -> git restore [--staged] {file}\n"
        "g %srt%s [s|m|h] {commit}          -> git reset [--soft|--mixed|--hard] {commit}\n"
        "g %srv%s {commit}                  -> git revert {commit}\n"
        "g %ssh%s {commit}                  -> git show {commit}\n"
        "g %st%s [a] {name} [m {\"msg\"}]     -> git tag [-a] {name} [-m {\"msg\"}]\n"
        , red, def, red, def
        , red, version_number, def
        , red, def
        , red, def
        , red, def
        //
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
        , red, def
     );
}
