#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//                             mm-dd.vvv
//                             with:
//                             mm  -> month
//                             dd  -> day
//                             vvv -> continous version number
const char version_number[] = "11-18.001";
const char red[] = "\033[31m";
const char def[] = "\033[0m";

void usage();

int main(int argc, char **argv) {
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
        "stuff:\n"
        "g %si%s [path]                     -> git init [path]\n"
        "g %sg%s {url} [folder]             -> git clone {url} [folder]\n"
        "g %ss%s                            -> git status\n"
        "g %sd%s [s] [commit1 commit2]      -> git diff [--staged] [commit1 commit2]\n"
        "g %sa%s {file | a}                 -> git add {file | -A}\n"
        "g %sc%s [a] [m {\"msg\"}]            -> git commit [-a] [-m {\"msg\"}]\n"
        "g %sb%s [d] {name}                 -> git branch [-d] {name}\n"
        "g %ssw%s [c] {branch}              -> git switch [-c] {branch}\n"
        "g %sco%s {commit}                  -> git checkout {commit}\n"
        "g %sm%s {branch}                   -> git merge {branch}\n"
        "g %sf%s [remote [branch]]          -> git fetch [remote [branch]]\n"
        "g %spl%s [r]                       -> git pull [--rebase]\n"
        "g %sps%s [u] [remote [branch|tag]] -> git push [-u] [remote [branch|tag]]\n"
        "g %sre%s [s] {file}                -> git restore [--staged] {file}\n"
        "g %srt%s [s|m|h] {commit}          -> git reset [--soft|--mixed|--hard] {commit}\n"
        "g %srv%s {commit}                  -> git revert {commit}\n"
        "g %sl%s [o] [number]               -> git log [--oneline] [-n {number}]\n"
        "g %ssh%s {commit}                  -> git show {commit}\n"
        "g %sst%s [p|l]                     -> git stash [pop|list]\n"
        "g %st%s [a] {name} [m {\"msg\"}]     -> git tag [-a] {name} [-m {\"msg\"}]\n"
        "g %sh%s                            -> prints this usage screen\n"
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
