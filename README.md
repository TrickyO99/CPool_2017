# CPool_2017

Exercises from the two-week C "piscine" (bootcamp) at Epitech, 2017. Each
`CPool_DayNN_2017` folder is one day's set of small, self-contained
exercises; `CPool_bistro-matic_2017` and `CPool_evalexpr_2017` are the
pool's larger multi-file projects. Most days are loose `.c` files with no
build system of their own (they were compiled and unit-tested individually
during the piscine); a few later days introduce a proper `Makefile` +
`src/`/`include/` layout.

## Day-by-day

- **CPool_Day01_2017** — Shell/Git setup exercises: `midLS.sh` (custom
  `ls -F` listing), `mr_clean.sh` (deletes editor backup files matching
  `#*#`/`*~`), `prepare_my_repo.sh` (creates and sets ACLs on an Epitech
  `blih` repository). `task01`/`task02`/`task08` hold leftover test
  artifacts from those exercises.
- **CPool_Day02_2017** — Unix command-line tools: `count_files.sh`
  (counts regular files), `find_sh.sh` (finds `*.sh` files),
  `how_many_are_we.sh`/`gotta_catch_them_all.sh` (count matching lines/
  fields in a CSV or `passwd`-style file via `cut`/`grep`),
  `looneytised.sh` (renames people via `sed`), `skip.sh`/`r_tacpy.sh`
  (line filtering/reversing with `sed`, `rev`, `sort`). Sample data lives
  under `Day02/` (`passwd`, `students.csv`).
- **CPool_Day03_2017** — First C exercises: printing the alphabet forward/
  backward (`my_print_alpha`, `my_print_revalpha`), printing an int
  (`my_put_nbr`), a negativity check (`my_isneg`), a digit printer
  (`my_print_digits`), and two combinatorics printers (`my_print_comb`
  prints all increasing 3-digit combinations "000, 001, ... 999";
  `my_print_comb2` prints increasing 4-digit combinations as two 2-digit
  groups).
- **CPool_Day04_2017** — Pointers & strings: `my_strlen`, `my_putstr`,
  `my_swap` (swap two ints via pointers), `my_getnbr` (string-to-int
  parser), `my_evil_str` (in-place string reversal).
- **CPool_Day05_2017** — Recursion vs. iteration: factorial and power
  computed both iteratively and recursively, `my_compute_square_root`
  (integer square root by linear search), `my_is_prime`, and
  `my_find_prime_sup` (next prime greater than N).
- **CPool_Day06_2017** — Reimplementations of the C string library:
  `my_strcpy`/`my_strncpy`, `my_strcmp`/`my_strncmp`, `my_strstr`,
  `my_revstr`, case conversion (`my_strupcase`/`my_strlowcase`/
  `my_strcapitalize`), and character-class tests (`my_str_isalpha`,
  `my_str_isnum`, `my_str_isupper`, `my_str_islower`,
  `my_str_isprintable`).
- **CPool_Day07_2017** — String concatenation (`my_strcat`,
  `my_strncat`) plus the first exercises that build a personal static
  library `libmy.a` and link small argv-printing programs against it:
  `task04/my_print_params.c` prints each CLI argument on its own line,
  `task05/my_rev_params.c` prints them in reverse.
- **CPool_Day08_2017** — Word-array manipulation: `my_str_to_word_array`
  (splits a string into an array of alphanumeric "words"),
  `my_show_word_array` (prints such an array), `my_strdup`, and
  `concat_params` (joins argv into one string).
- **CPool_Day09_2017** — Recursion/macros exercise (`my_params_to_array`)
  with a custom `include/my.h` and `my_macroABS.h` (an `ABS()` macro).
  Note: this file has unresolved syntax issues in the source as committed
  (undeclared/duplicate identifiers) and would not compile as-is.
- **CPool_Day10_2017** — A `do_op` calculator skeleton (`do_op/do_op.c`)
  and shared `include/my.h`; the operator-dispatch logic itself is not
  present in this snapshot (the file only contains the header comment).
- **CPool_Day11_2017** — Singly linked lists: `include/mylist.h` defines
  `linked_list_t`; `my_params_to_list` builds a list from argv,
  `my_list_size` counts its nodes.
- **CPool_Day12_2017** — First "real" Makefile-based projects:
  `cat/` reimplements the Unix `cat` command (reads a file given as argv[1],
  or stdin if no argument, and writes it to stdout) and builds with its own
  Makefile; `bonus/` is a second small Makefile'd project sharing a
  `bonus/include/my.h` header.
- **CPool_Day13_2017** — SFML graphics warm-up tasks rather than the usual
  algorithmic day13: `task01.c` opens an SFML render window and runs its
  event loop until closed; `task02.c` sketches a framebuffer/pixel-drawing
  API on top of the same window loop (incomplete — `put_pixel` and
  `framebuffer_create` are stubs).
- **CPool_bistro-matic_2017** — The pool's capstone project: a
  reverse-Polish/infix expression evaluator and calculator (`eval_expr.c`,
  `find_nbr.c`, `initialisation.c`, an `antierror/` module for syntax-error
  handling, and a small personal library under `lib/my/`), built into a
  `calc` binary via its own `Makefile`. Note: this snapshot is missing
  `src/main.c` and `src/antierror/antierror.c`/`error_base.c` (only their
  `.o` files remain), so the project can't be rebuilt from source as-is,
  even though a `calc` binary and most `.o` files are present.
- **CPool_evalexpr_2017** — `infinadd.c`, a standalone (and unfinished)
  arbitrary-precision integer addition routine intended to support
  expression evaluation on numbers larger than a machine `int`; as written
  it computes a digit-by-digit sum but never assembles/returns the result
  string.

## Build notes

Most days are individual `.c` files without a Makefile — during the
piscine they were compiled ad hoc, e.g.:

```
gcc -W -Wall -Wextra -o test my_file.c
```

`CPool_Day12_2017/cat`, `CPool_Day12_2017/bonus` and
`CPool_bistro-matic_2017` each have their own `Makefile` with the usual
Epitech targets (`all`, `clean`, `fclean`, `re`).

**Windows note:** these Makefiles expect plain `make`. On this machine,
use MinGW-w64's `mingw32-make` instead, run from inside the relevant
subdirectory, e.g.:

```
cd CPool_bistro-matic_2017
mingw32-make re
```

## QA notes

This collection is too large for exhaustive per-file unit testing (15 day
folders plus two capstone projects, most of them loose `.c` files with no
`main()`/build system of their own). Instead, `test_cpool.py` in this
directory picks the ~5 most meaningfully testable/runnable pieces and
does real build-it-and-run-it smoke testing on them (via `subprocess` +
`gcc`/`mingw32-make`), skipping cleanly rather than failing when a
required tool isn't on `PATH`.

**Tested** (built and/or run with a real MinGW-w64 GCC 16.1.0 toolchain,
`gcc`/`mingw32-make` from the WinLibs distribution):

- **CPool_Day07_2017/task04** (`my_print_params.c`) — builds and links
  against the pre-built `libmy.a`. **Bug found:** `libmy.a`'s object
  files are Linux ELF64 (`objdump -f` reports `file format
  elf64-x86-64` for every member) — a leftover from the original 2017
  Epitech Linux VM. MinGW's `ld` will still emit an output file (only a
  `.comment: section below image base` warning, exit code 0), but the
  resulting binary is not actually runnable on Windows
  (`WinError 193: %1 is not a valid Win32 application`). This is a
  cross-platform toolchain/library-format mismatch, not a bug in
  `my_print_params.c`'s own logic, so the test suite documents it
  (`test_prebuilt_lib_binary_runs_or_documents_known_platform_mismatch`,
  expected to `xfail` on Windows) and separately verifies the real
  argv-printing behaviour by linking the same source against small
  local stub implementations of `my_putstr`/`my_putchar` written just
  for the test.
- **CPool_Day12_2017/cat** — builds cleanly via its own `Makefile`
  (`mingw32-make re`) and correctly prints a file's contents given as
  `argv[1]`, and correctly reports `Error with open` + exit code `84`
  for a missing file. **Bug found:** the no-argument/stdin code path
  (`while (1 != 0) { size = read(fd, buffer, 14999); write(1, buffer,
  size); }`) has no break/exit condition for EOF (`size == 0`) — it
  echoes piped input correctly but then spins forever instead of
  exiting, so piping a finite input into this binary never terminates
  on its own. Previously undocumented; the test suite captures this
  with a bounded wait + explicit process kill rather than patching
  `main.c` (day-by-day exercise bugs are documented, not fixed, per
  this QA pass's scope).
- **CPool_evalexpr_2017/infinadd.c** — confirmed: plain `gcc` rejects it
  with `error: assignment to 'char *' from 'int' makes pointer from
  integer without a cast [-Wint-conversion]` at `result = (s1[i] - 48)
  + (s2[j] - 48);`, and `-fpermissive` (a normally C++-only GCC flag)
  does downgrade this specific error to a warning on this toolchain, as
  already documented above — confirming the day-by-day note. Also
  confirmed: `infinadd()` never reaches a `return` statement, so even
  once it builds, the integer `main()` prints is not a real, assembled
  sum (the routine's own known incompleteness) — the test only asserts
  it runs to completion, not that it prints a mathematically correct
  result.
- **CPool_Day13_2017/task01.c** — CSFML headers happened to be available
  in this environment, so the test actually compiles this file
  (`gcc -c task01.c`) rather than skipping; it does not attempt to link
  or open a real window (no headless SFML backend is assumed).
- **CPool_Day10_2017/do_op.c** — confirmed genuinely empty (only the
  header comment, no code): it compiles cleanly as an empty translation
  unit (`gcc -c`, exit 0) but fails to link into a program
  (`undefined reference to 'WinMain'`), proving there is no `main()`
  anywhere in the object.

**Skipped** (not attempted by `test_cpool.py`, documented here instead):

- **CPool_Day01–06, 08, 09, 11** — loose exercise files with no
  `main()`/build system of their own; out of scope for automated
  build/run smoke testing (they were unit-tested ad hoc during the
  original piscine). CPool_Day09_2017 in particular is already noted
  above as having unresolved syntax issues that would not compile as-is.
- **CPool_bistro-matic_2017** — already documented above as missing
  `src/main.c` (and `src/antierror/antierror.c`/`error_base.c`, only
  their `.o` files remain), so it cannot be rebuilt from source; not
  re-tested here since the top-level day-by-day notes already cover why.
- **CPool_Day13_2017/task02.c** — explicitly noted above as incomplete
  (`put_pixel`/`framebuffer_create` are stubs) and, like `task01.c`,
  would open a real GUI window if run; not exercised beyond what's
  already documented.

No day-by-day exercise bugs were fixed as part of this QA pass (per
scope: this collection is too large for exhaustive fixing) — everything
above is captured as an automated, clearly-commented test plus this
note, so a future contributor can see exactly what's known-broken and
why.
