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
const char version_number[] = "11-20.001";
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
     *  sorry but this is the best implementation
     *  you'll get out of an eepy ass at almost 2AM
     */
    if (argc == 2) {
        strcpy(strn1, argv[1]);
        if (strcmp(strn1, "i") == 0 || strcmp(strn1, "ini") == 0 ||
            strcmp(strn1, "in") == 0 || strcmp(strn1, "init") == 0) {
            system("git init");
            return 0;
        } else if (strcmp(strn1, "s") == 0 || strcmp(strn1, "stat") == 0 ||
                   strcmp(strn1, "st") == 0 || strcmp(strn1, "statu") == 0 ||
                   strcmp(strn1, "sta") == 0 || strcmp(strn1, "status") == 0) {
            system("git status");
            return 0;
        } else if (strcmp(strn1, "d") == 0 || strcmp(strn1, "dif") == 0 ||
                   strcmp(strn1, "di") == 0 || strcmp(strn1, "diff") == 0) {
            system("git diff");
            return 0;
        } else if (strcmp(strn1, "c") == 0 || strcmp(strn1, "comm") == 0 ||
                   strcmp(strn1, "co") == 0 || strcmp(strn1, "commi") == 0 ||
                   strcmp(strn1, "com") == 0 || strcmp(strn1, "commit") == 0) {
            system("git commit");
            return 0;
        } else if (strcmp(strn1, "f") == 0 || strcmp(strn1, "fetc") == 0 || 
                   strcmp(strn1, "fe") == 0 || strcmp(strn1, "fetch") == 0 ||
                   strcmp(strn1, "fet") == 0) {
            system("git fetch");
        } else if (strcmp(strn1, "p") == 0 || strcmp(strn1, "pus") == 0 ||
                   strcmp(strn1, "pu") == 0 || strcmp(strn1, "push") == 0) {
            system("git push");
        } else if (strcmp(strn1, "m") == 0 || strcmp(strn1, "merg") == 0 ||
                   strcmp(strn1, "me") == 0 || strcmp(strn1, "merge") == 0 ||
                   strcmp(strn1, "mer") == 0) {
            system("git merge");
        } else if (strcmp(strn1, "h") == 0 || strcmp(strn1, "hel") == 0 ||
                   strcmp(strn1, "he") == 0 || strcmp(strn1, "help") == 0) {
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
       "g %si%s [path]                     -> git %si%snit [path]\n"

       "g %ss%s                            -> git %ss%status\n"
       "g %sd%s [s] [commit1 commit2]      -> git %sd%siff [--staged] [commit1 commit2]\n"
       "g %sc%s [a] [m {\"msg\"}]            -> git %sc%sommit [-a] [-m {\"msg\"}]\n"
       "g %sf%s [remote [branch]]          -> git %sf%setch [remote [branch]]\n"
       "g %sm%s [branch]                   -> git %sm%serge [branch]\n"
       "g %sp%s [u] [remote [branch|tag]]  -> git %sp%sush [-u] [remote [branch|tag]]\n"
       "g %spl%s [r]                       -> git %sp%sul%sl%s [--rebase]\n"
       "g %sl%s [o] [number]               -> git %sl%sog [--oneline] [-n {number}]\n"
       "g %sst%s [p|l]                     -> git %sst%sash [pop|list]\n"
       "g %sh%s                            -> prints this usage screen\n"
       "==============================================================\n"
       "g %sg%s {url} [folder]             -> git %sc%slone {url} [folder]\n"
       "g %sa%s {file | a}                 -> git %sa%sdd {file | -A}\n"
       "g %sb%s [d] {name}                 -> git %sb%sranch [-d] {name}\n"
       "g %ssw%s [c] {branch}              -> git %ssw%sitch [-c] {branch}\n"
       "g %sco%s {commit}                  -> git %sc%sheck%so%sut {commit}\n"
       "g %sre%s [s] {file}                -> git %sre%sstore [--staged] {file}\n"
       "g %srt%s [s|m|h] {commit}          -> git %sr%sese%st%s [--soft|--mixed|--hard] {commit}\n"
       "g %srv%s {commit}                  -> git %sr%se%sv%sert {commit}\n"
       "g %ssh%s {commit}                  -> git %ssh%sow {commit}\n"
       "g %st%s [a] {name} [m {\"msg\"}]     -> git %st%sag [-a] {name} [-m {\"msg\"}]\n"
        , red, def, red, def
        , red, version_number, def
        , red, def
        , red, def
        , red, def
        //
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def, red, def 
        , red, def, red, def, red, def 
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def
        , red, def, red, def, red, def 
        , red, def, red, def
        , red, def, red, def, red, def 
        , red, def, red, def, red, def 
        , red, def, red, def
        , red, def, red, def
    );
}
