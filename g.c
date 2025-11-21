#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  g - the *wrapper* git wrapper
 *      $version_number
 */


//                             mm-dd.vvv
//                             with:
//                             mm  -> month
//                             dd  -> day
//                             vvv -> continous version number
const char version_number[] = "β 11-20.001";

const char red[] = "\033[31m";
const char def[] = "\033[0m";

char strn1[2048]; // arg buffer 1
char strn2[2048]; // arg buffer 2
char strn3[2048]; // arg buffer 3
char strn4[2048]; // arg buffer 4

const char *init_vars[] = {"i", "I", "in", "ini", "init", NULL};
const char *status_vars[] = {"s", "S", "st", "sta", "stat", "statu", "status", NULL};
const char *diff_vars[] = {"d", "D", "di", "dif", "diff", NULL};
const char *commit_vars[] = {"c", "C", "co", "com", "comm", "commi", "commit", NULL};
const char *fetch_vars[] = {"f", "F", "fe", "fet", "fetc", "fetch", NULL};
const char *merge_vars[] = {"m", "M", "me", "mer", "merg", "merge", NULL};
const char *push_vars[] = {"p", "P", "pu", "pus", "push", NULL};
const char *pull_vars[] = {"pl", "Pl", "pL", "PL", "pul", "pull", NULL};
const char *help_vars[] = {"h", "H", "he", "hel", "help", "-h", "--help", NULL};
const char *log_vars[] = {"l", "L", "lo", "log", NULL};
const char *stash_vars[] = {"st", "St", "sT", "ST", "sta", "stas", "stash", NULL};
const char *clone_vars[] = {"g", "G", "cl", "clo", "clon", "clone", NULL};
const char *add_vars[] = {"a", "A", "ad", "add", NULL};
const char *branch_vars[] = {"b", "B", "br", "bra", "bran", "branc", "branch", NULL};
const char *switch_vars[] = {"sw", "Sw", "sW", "SW", "swi", "swit", "switc", "switch", NULL};
const char *checkout_vars[] = {"co", "Co", "cO", "CO", "ch", "che", "chec", "check", "checko", "checkou", "checkout", NULL};
const char *restore_vars[] = {"re", "Re", "rE", "RE", "res", "rest", "resto", "restor", "restore", NULL};
const char *reset_vars[] = {"rt", "Rt", "rT", "RT", "rese", "reset", NULL}; // excluded 're' and 'res'
const char *revert_vars[] = {"rv", "Rv", "rV", "RV", "re", "rev", "reve", "rever", "revert", NULL};
const char *remote_vars[] = {"r", "R", "r", "rem", "remo", "remot", "remote", NULL}; // excluded "re"
const char *show_vars[] = {"sh", "Sh", "sH", "SH", "sho", "show", NULL};
const char *remove_vars[] = {"rm", "Rm", "rM", "RM", "remov", "remove", NULL}; // excluded "re", "rem" and "remo"
const char *tag_vars[] = {"t", "T", "ta", "tag", NULL};

const char *staged_vars[] = {"s", "S", "st", "sta", "stag", "stage", "staged", "--staged", NULL};
//const char *add_vars[] = {"a", "A", "ad", "add", NULL};
const char *message_vars[] = {"m", "M", "ms", "msg", NULL};
const char *upstream_vars[] = {"u", "U", "up", "ups", "upst", "upstr", "upstre", "upstrea", "upstream", "--set-upstream", NULL};
const char *rebase_vars[] = {"r", "R", "re", "reb", "reba", "rebas", "rebase", "--rebase", NULL};
const char *oneline_vars[] = {"o", "O", "on", "one", "onel", "oneli", "onelin", "oneline", "--oneline", NULL};
const char *number_vars[] = {"n", "N", "nu", "num", "numb", "numbe", "number", "-n", NULL};
const char *pop_vars[] = {"p", "P", "po", "pop", "pp", NULL};
const char *list_vars[] = {"l", "L", "li", "lis", "list", "ls", NULL};
const char *delete_vars[] = {"d", "D", "de", "del", "dele", "delet", "delete", "-d", NULL};
const char *create_vars[] = {"c", "C", "cr", "cre", "crea", "creat", "create", NULL};
const char *soft_vars[] = {"s", "S", "so", "sof", "soft", "--soft", NULL};
const char *mixed_vars[] = {"m", "M", "mi", "mix", "mixe", "mixed", "--mixed", NULL};
const char *hard_vars[] = {"h", "H", "ha", "har", "hard", "--hard", NULL};
const char *get_url_vars[] = {"g", "G", "gu", "Gu", "GU", "gU", "ge", "get", "get-", "get-u", "get-ur", "get-url", NULL};
const char *all_vars[] = {"a", "A", "al", "all", "--all", "-A", NULL};
const char *annotated_vars[] = {"a", "A", "an", "ann", "anno", "annot", "annota", "annotat", "annotate", "annotated", "-a", NULL};
const char *github_link_vars[] = {"gh/", "Gh/", "gH/", "GH/", "gi/", "git/", "gith/", "githu/", "github/", NULL};

const char *yes_vars[] = {"y", "Y", "ye", "yes", "Yes", "YES", NULL};
const char *no_vars[] = {"n", "N", "no", "No", "NO", NULL};
const char space[] = " ";

int matches(const char *cmd, const char *list[]);
void spaceStrings(char *fir_str, char *sec_str);
void usage();

int main(int argc, char **argv) {
    /*
     *  the structure is:
     *  if (n. of argc)
     *  — options with that n. of argc
     *  else if (another n. of argc)
     *  — options with that other n. of argc
     *  and so on and so forth.
     *  sorry but this is the best implementation that
     *  you'll get out of an eepy ass at almost 2AM, luv
     */
    if (argc == 2) {                                       // g x
        strcpy(strn1, argv[1]);

        if (matches(strn1, init_vars) == 0) {
            system("git init");
            return 0;
        }
        else if (matches(strn1, status_vars) == 0) {
            system("git status");
            return 0;
        }
        else if (matches(strn1, diff_vars) == 0) {
            system("git diff");
            return 0;
        }
        else if (matches(strn1, commit_vars) == 0) {
            system("git commit");
            return 0;
        }
        else if (matches(strn1, fetch_vars) == 0) {
            system("git fetch");
            return 0;
        }
        else if (matches(strn1, merge_vars) == 0) {
            system("git merge");
            return 0;
        }
        else if (matches(strn1, push_vars) == 0) {
            system("git push");
            return 0;
        }
        else if (matches(strn1, pull_vars) == 0) {
            system("git pull");
            return 0;
        }
        else if (matches(strn1, log_vars) == 0) {
            system("git log");
            return 0;
        }
        else if (matches(strn1, stash_vars) == 0) {
            system("git stash");
            return 0;
        }
        else if (matches(strn1, tag_vars) == 0) {
            system("git tag");
            return 0;
        }
        else if (matches(strn1, help_vars) == 0) {
            usage();
            return 0;
        }
    } else if (argc == 3) {                                // g x y
        strcpy(strn1, argv[1]);
        strcpy(strn2, argv[2]);

        if (matches(strn1, init_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git init");
                return 0;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git init ";
                strcat(command_buffer, strn2); // TODO: use snprintf or anything safer than strcat()
                system(command_buffer); // git init [path]
                return 0;
            }
        } else if (matches(strn1, diff_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git diff");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, staged_vars) == 0) {
                    system("git diff --staged");
                    return 0;
                } else {
                    char command_buffer[8192] = "git diff ";
                    strcat(command_buffer, strn2);
                    system("git diff"); // git diff commit
                    return 0;
                }
            }
        } else if (matches(strn1, commit_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git commit");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, add_vars) == 0) {
                    system("git commit -a");
                    return 0;
                } // the commit_message_vars check is in the argc == 4,
            }     // because it demands another argument too
                  // this obviosuly applies to every command with `-m`
                  // i.e. `git tag`
        } else if (matches(strn1, fetch_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git fetch");
                return 0;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git fetch ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git fetch [remote]
                return 0;
            }
        } else if (matches(strn1, merge_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git merge");
                return 0;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git merge ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git merge [branch]
                return 0;
            }
        } else if (matches(strn1, push_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git push");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, upstream_vars) == 0) {
                    system("git push --upstream");
                           return 0;
                } else {
                    char command_buffer[8192] = "git push ";
                    strcat(command_buffer, strn2);
                    system(command_buffer); // git push [remote]
                    return 0;
                }
            }
        } else if (matches(strn1, pull_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git pull");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, rebase_vars)) {
                    system("git pull --rebase");
                    return 0;
                } else {
                    printf(":: %sunknown%s option for '%spull%s': \"%s%s%s\".\n", red, def, red, def, red, strn2, def);
                    printf(":: running '%sgit pull --rebase%s'.\n", red, def);
                    system("git pull");
                   return 0;
                }
            }
        } else if (matches(strn1, log_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git log");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, oneline_vars) == 0) {
                    system("git tag --oneline");
                    return 0;
                } else {
                    printf(":: %sunknown%s option for '%stag%s': \"%s%s%s\".\n", red, def, red, def, red, strn2, def);
                    printf(":: running '%sgit tag%s'.\n", red, def);
                    system("git tag");
                    return 0;
                }
            }
        } else if (matches(strn1, stash_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git stash");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, pop_vars) == 0) {
                    system("git stash pop");
                    return 0;
                } else if (matches(strn2, list_vars) == 0) {
                    system("git stash list");
                } else {
                    printf(":: %sunknown%s option for '%sstash%s': \"%s%s%s\".\n", red, def, red, def, red, strn2, def);
                    printf(":: running '%sgit stash%s'.\n", red, def);
                    system("git stash");
                    return 0;
                }
            }
        } else if (matches(strn1, clone_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git clone");
                return 0;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, github_link_vars) == 0) {
                    char command_buffer[8192] = "git clone https://github.com/";
                    strcat(command_buffer, strn2);
                    system(command_buffer); // git clone https://github.com/{user}/{repo}[.git]
                    return 0;
                } else {
                    char command_buffer[8192] = "git clone ";
                    strcat(command_buffer, strn2);
                    system(command_buffer); // git clone {url}
                    return 0;
                }
            }
        } else if (matches(strn1, add_vars) == 0) {
            char dym1[] = "y";
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %sadd%s\n", red, def, red, def);
                printf(":: did you mean \"g a .\"? (Y|y/N|n - Default: y)\n:: ");
                scanf("%s", dym1);
                if (matches(dym1, yes_vars) == 0 || strcmp(dym1, "\n") == 0) {
                    system("git add .");
                }
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, all_vars) == 0) {
                    system("git add -A");
                    return 0;
                } else {
                    char command_buffer[8192] = "git add ";
                    strcat(command_buffer, strn2);
                    system(command_buffer); // git add {file}
                    return 0;
                }
            }
        } else if (matches(strn1, checkout_vars) == 0) {
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %scheckout%s\n", red, def, red, def);
                printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                system("git checkout");
                return 1;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git checkout ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git checkout {commit}
                return 0;
            }
        } else if (matches(strn1, revert_vars) == 0) {
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %srevert%s\n", red, def, red, def);
                printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                system("git revert");
                return 1;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git revert ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git revert {commit}
                return 0;
            }
        } else if (matches(strn1, show_vars) == 0) {
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %sshow%s\n", red, def, red, def);
                printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                system("git show");
                return 1;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git show ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git show {commit}
                return 0;
            }
        } else if (matches(strn1, tag_vars) == 0) {
            if (strlen(strn2) == 0) {
                system("git tag");
                return 0;
            } else if (strlen(strn2) > 0) {
              char command_buffer[8192] = "git tag ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git tag [name]
                return 0;
            }
        } else if (matches(strn1, remove_vars) == 0) {
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %sshow%s\n", red, def, red, def);
                printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                system("git rm");
                return 1;
            } else if (strlen(strn2) > 0) {
                char command_buffer[8192] = "git rm ";
                strcat(command_buffer, strn2);
                system(command_buffer); // git rm {file}
                return 0;
            }
        }
    } else if (argc == 4) {                                // g x y z
        strcpy(strn1, argv[1]);
        strcpy(strn2, argv[2]);
        strcpy(strn3, argv[3]);

        if (matches(strn1, diff_vars) == 0) {
            if (strlen(strn2) == 0) {
                printf(":: %sno option%s was given for %sdiff%s\n", red, def, red, def);
                printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                system("git diff");
                return 1;
            } else if (strlen(strn2) > 0) {
                if (matches(strn2, staged_vars) == 0) {
                    system("git diff --staged");
                    return 0;
                } else {
                    if (strlen(strn3) == 0) {
                        printf(":: %sno option%s was given for %sdiff%s\n", red, def, red, def);
                        printf(":: autocomplete %simpossible%s, bailing out, %ssorry%s.\n", red, def, red, def);
                        system("git diff");
                        return 1;
                    } else if (strlen(strn3) > 0) {
                        char command_buffer[8192] = "git diff ";
                        spaceStrings(strn2, strn3); // "strn2 strn3"
                        strcat(command_buffer, strn2);
                        system(command_buffer); // git diff commit1 commit2
                        return 0;
                    }
                }
            }
        } else if (matches(strn1, commit_vars) == 0) {
            if (strlen(strn2) == 0) {
                //
            } else if (strlen(strn2) > 0) {
                //
            }
            if (matches(strn2, message_vars) == 0) {
                if (strlen(strn3) == 0) {
                    //
                } else if (strlen(strn3) > 0) {
                    //
                }
            } else if (matches(strn2, add_vars) == 0) {
                if (strlen(strn3) == 0) {
                    //
                } else if (strlen(strn3) > 0) {
                    //
                }
            }
        }
    }
    
    usage();
    return 0;
}

int matches(const char *cmd, const char *list[]) {
    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(cmd, list[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void spaceStrings(char *fir_str, char *sec_str) {
    strcat(fir_str, space);
    strcat(sec_str, fir_str);
}

void usage() {
    printf(
        "%sg%s - the %spermissive%s git wrapper\n"
        "spinning version %s%s%s\n"
        "==============================================================\n"
        "generally: 'g [%sstuff%s]', got it?\n"
        "[] -> %soptional%s | {} -> %srequired%s\n"
        "==============================================================\n"
        "stuff;\n"
       "g %si%s [path]                     -> git %si%snit [path]\n"

       "g %ss%s                            -> git %ss%status\n"
       "g %sd%s [s] [commit1 [commit2]]    -> git %sd%siff [--staged] [commit1 [commit2]]\n"
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
       "g %sg gh/{username}/{git}[.git]%s  -> git clone https://github.com/{user}/{repo}[.git]\n"
       "g %sa%s {file | a}                 -> git %sa%sdd {file | -A}\n"
       "g %sb%s [d] {name}                 -> git %sb%sranch [-d] {name}\n"
       "g %ssw%s [c] {branch}              -> git %ssw%sitch [-c] {branch}\n"
       "g %sco%s {commit}                  -> git %sc%sheck%so%sut {commit}\n"
       "g %sre%s [s] {file}                -> git %sre%sstore [--staged] {file}\n"
       "g %srt%s [s|m|h] {commit}          -> git %sr%sese%st%s [--soft|--mixed|--hard] {commit}\n"
       "g %srv%s {commit}                  -> git %sr%se%sv%sert {commit}\n"
       "g %sr%s {a{name{url}}|g{name}}     -> git %sr%semote {add{name{url}}|get-url{name}}\n"
       "g %ssh%s {commit}                  -> git %ssh%sow {commit}\n"
       "g %st%s [a] {name} [m {\"msg\"}]     -> git %st%sag [-a] {name} [-m {\"msg\"}]\n"
       "g %srm%s {file}                    -> git %srm%s {file}\n"
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
        , red, def, red, def
        , red, def, red, def, red, def 
        , red, def, red, def
        , red, def, red, def, red, def 
        , red, def, red, def, red, def 
        , red, def, red, def
        , red, def, red, def
        , red, def
    );
}

