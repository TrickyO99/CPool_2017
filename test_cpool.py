"""
Smoke-test suite for CPool_2017.

CPool_2017 is a large collection of day-by-day Epitech C "piscine"
exercises (15 day folders plus two capstone projects -- see this
project's README.md for the full day-by-day breakdown). Given the sheer
size of the collection, and that most days are loose .c files with no
main()/build system of their own (they were compiled and unit-tested ad
hoc during the actual piscine), this suite does NOT attempt exhaustive
per-file unit testing.

Instead it picks the ~5 most meaningfully testable/runnable pieces and
does real build-it-and-run-it smoke testing on them via subprocess
(gcc / mingw32-make + the resulting binaries):

  1. CPool_Day07_2017/task04        - my_print_params.c, links against a
                                       pre-built libmy.a (known buildable).
  2. CPool_Day12_2017/cat           - has its own working Makefile.
  3. CPool_evalexpr_2017/infinadd.c - builds with -fpermissive because of
                                       a known type-mismatch bug (int
                                       assigned to a char* without a
                                       cast); documented, not fixed.
  4. CPool_Day13_2017/task01.c      - builds against CSFML (skipped if
                                       CSFML isn't installed).
  5. CPool_Day10_2017/do_op.c       - a known EMPTY stub (only the header
                                       comment); documents that it
                                       compiles as a translation unit but
                                       cannot be linked into a program
                                       (no main()).

All C-toolchain-dependent tests are marked to SKIP (never fail) when gcc
and/or mingw32-make/make aren't found on PATH, or when a specific
optional dependency (CSFML) isn't available, so this file behaves
correctly both on a fully-equipped piscine dev box and on a plain
checkout with no C toolchain at all. See the "QA notes" section appended
to README.md for what actually ran (vs. was skipped) in the environment
this suite was authored in, and for bugs found along the way.
"""
import shutil
import subprocess
import sys
import textwrap

import pytest

ROOT = __import__("pathlib").Path(__file__).parent

GCC = shutil.which("gcc")
MAKE = shutil.which("mingw32-make") or shutil.which("make")

requires_gcc = pytest.mark.skipif(
    GCC is None, reason="gcc not found on PATH in this environment"
)
requires_make = pytest.mark.skipif(
    MAKE is None, reason="mingw32-make/make not found on PATH in this environment"
)


def run(cmd, cwd=None, timeout=30):
    return subprocess.run(
        cmd, cwd=cwd, capture_output=True, text=True, timeout=timeout
    )


# ---------------------------------------------------------------------------
# 1. CPool_Day07_2017/task04 -- my_print_params.c + libmy.a
# ---------------------------------------------------------------------------
class TestDay07Task04PrintParams:
    """my_print_params.c calls my_putstr()/my_putchar(), which are NOT
    defined in the .c file itself -- they come from the pre-built
    libmy.a sitting right next to it. This is a real, known-buildable
    piece from the exercise set: compile + statically link, then check
    that each argv entry is printed on its own line."""

    DIR = ROOT / "CPool_Day07_2017" / "task04"
    SRC = DIR / "my_print_params.c"
    LIB = DIR / "libmy.a"

    def test_source_and_prebuilt_lib_are_present(self):
        assert self.SRC.is_file()
        assert self.LIB.is_file()

    @requires_gcc
    def test_builds_and_prints_each_argv_entry_on_its_own_line(self, tmp_path):
        exe = tmp_path / "my_print_params.exe"
        build = run(
            [
                GCC, "-W", "-Wall",
                str(self.SRC),
                "-L", str(self.DIR), "-lmy",
                "-o", str(exe),
            ]
        )
        assert build.returncode == 0, f"build failed:\n{build.stderr}"
        assert exe.is_file()

        result = run([str(exe), "hello", "world"])
        assert result.returncode == 0
        # main() loops `while (argc > 0)` printing argv[i] for i counting
        # up from 0, so argv[0] (the program path) is printed too, then
        # every extra argument -- one per line, in order.
        lines = result.stdout.splitlines()
        assert lines[-2:] == ["hello", "world"]

    @requires_gcc
    def test_no_extra_arguments_prints_only_program_name(self, tmp_path):
        exe = tmp_path / "my_print_params.exe"
        build = run(
            [GCC, str(self.SRC), "-L", str(self.DIR), "-lmy", "-o", str(exe)]
        )
        assert build.returncode == 0, f"build failed:\n{build.stderr}"

        result = run([str(exe)])
        assert result.returncode == 0
        assert len(result.stdout.splitlines()) == 1


# ---------------------------------------------------------------------------
# 2. CPool_Day12_2017/cat -- has its own working Makefile
# ---------------------------------------------------------------------------
class TestDay12Cat:
    """cat/ reimplements the Unix `cat` command and has a real Makefile
    (all/clean/fclean/re targets). Build it with mingw32-make and check
    both the "read a file given as argv[1]" and "read stdin" code
    paths, plus the documented error path for a missing file."""

    DIR = ROOT / "CPool_Day12_2017" / "cat"

    def test_makefile_and_source_present(self):
        assert (self.DIR / "Makefile").is_file()
        assert (self.DIR / "main.c").is_file()

    @requires_make
    @requires_gcc
    def test_builds_via_makefile(self):
        run([MAKE, "fclean"], cwd=self.DIR)  # start from a clean slate
        build = run([MAKE, "re"], cwd=self.DIR)
        assert build.returncode == 0, f"make re failed:\n{build.stdout}\n{build.stderr}"
        exe = self.DIR / "cat"
        exe_win = self.DIR / "cat.exe"
        assert exe.is_file() or exe_win.is_file()

    @requires_make
    @requires_gcc
    def test_prints_file_contents_given_as_argument(self, tmp_path):
        run([MAKE, "re"], cwd=self.DIR)
        exe = self._binary()

        sample = tmp_path / "sample.txt"
        sample.write_text("hello from cat\n")
        result = run([str(exe), str(sample)])
        assert result.returncode == 0
        assert result.stdout == "hello from cat\n"

    @requires_make
    @requires_gcc
    def test_reads_stdin_when_no_argument_given(self):
        run([MAKE, "re"], cwd=self.DIR)
        exe = self._binary()

        result = subprocess.run(
            [str(exe)],
            input="piped through stdin\n",
            capture_output=True,
            text=True,
            timeout=10,
        )
        assert "piped through stdin" in result.stdout

    @requires_make
    @requires_gcc
    def test_missing_file_reports_error_and_exit_84(self, tmp_path):
        run([MAKE, "re"], cwd=self.DIR)
        exe = self._binary()

        missing = tmp_path / "does_not_exist.txt"
        result = run([str(exe), str(missing)])
        assert result.returncode == 84
        assert "Error with open" in result.stderr

    def _binary(self):
        exe = self.DIR / "cat.exe"
        if exe.is_file():
            return exe
        return self.DIR / "cat"


# ---------------------------------------------------------------------------
# 3. CPool_evalexpr_2017/infinadd.c -- known type-mismatch bug
# ---------------------------------------------------------------------------
class TestEvalexprInfinadd:
    """infinadd.c is an unfinished arbitrary-precision addition routine.
    Per the top-level README, it "computes a digit-by-digit sum but
    never assembles/returns the result string" -- and it has a real
    type-mismatch bug: `result` is declared `char *` but line
    `result = (s1[i] - 48) + (s2[j] - 48);` assigns it a plain `int`
    with no cast, so on a strict modern C compiler this is an
    incompatible-pointer-from-integer error, not just a warning. It's
    documented (in the README's per-day breakdown and here) rather than
    fixed -- fixing the algorithm is out of scope for this QA pass.
    `-fpermissive` (a GCC flag that downgrades certain errors to
    warnings) is required to get this specific file through the
    compiler as-is."""

    SRC = ROOT / "CPool_evalexpr_2017" / "infinadd.c"

    def test_source_present(self):
        assert self.SRC.is_file()

    def test_known_bug_is_present_in_source(self):
        """Static documentation check: pin down the exact line that
        causes the type mismatch, so this test starts failing (and
        flags a README update) if the file is ever edited/fixed."""
        text = self.SRC.read_text()
        assert "char\t*result = NULL;" in text or "char *result = NULL;" in text
        assert "result = (s1[i] - 48) + (s2[j] - 48);" in text
        # infinadd() is declared to return int but has no return
        # statement anywhere in its body -- also part of the "unfinished"
        # state documented in the README.
        body_start = text.index("int\tinfinadd")
        body_end = text.index("int\tmain")
        assert "return" not in text[body_start:body_end]

    @requires_gcc
    def test_builds_with_fpermissive(self, tmp_path):
        exe = tmp_path / "infinadd.exe"
        build = run(
            [GCC, "-fpermissive", "-w", str(self.SRC), "-o", str(exe)]
        )
        if build.returncode != 0:
            pytest.xfail(
                "infinadd.c's known type-mismatch bug (int assigned to a "
                "char* without a cast) is not tolerated by this GCC build "
                f"even with -fpermissive; compiler said:\n{build.stderr}"
            )
        assert exe.is_file()

    @requires_gcc
    def test_result_is_never_assembled_or_returned(self, tmp_path):
        """Even when it builds, infinadd() never returns a meaningful
        value (see test_known_bug_is_present_in_source) -- main() prints
        whatever garbage int comes back from the fallen-off-the-end
        function. This documents that the printed "sum" is not
        trustworthy, rather than asserting any particular number."""
        exe = tmp_path / "infinadd.exe"
        build = run([GCC, "-fpermissive", "-w", str(self.SRC), "-o", str(exe)])
        if build.returncode != 0:
            pytest.skip("infinadd.c does not build in this environment")
        result = run([str(exe), "123", "456"])
        # We only assert it runs to completion without crashing when
        # given well-formed digit strings -- NOT that it prints 579
        # (the mathematically correct sum), because the routine never
        # assembles/returns a real result (documented stub behaviour).
        assert result.returncode == 0


# ---------------------------------------------------------------------------
# 4. CPool_Day13_2017/task01.c -- builds against CSFML
# ---------------------------------------------------------------------------
class TestDay13Task01Sfml:
    """task01.c opens an SFML render window and runs its event loop.
    This needs the CSFML dev headers/libs, which are an optional native
    dependency unlikely to be present on every machine -- so this test
    is skipped (not failed) when they're missing, and skipped outright
    when it would open a real GUI window (no headless SFML backend is
    assumed here). We only prove the code *compiles* against CSFML."""

    SRC = ROOT / "CPool_Day13_2017" / "task01.c"

    def test_source_present(self):
        assert self.SRC.is_file()

    @requires_gcc
    def test_compiles_against_csfml(self, tmp_path):
        obj = tmp_path / "task01.o"
        # Compile-only (-c): proves the SFML headers/types are found and
        # the code is syntactically/semantically valid, without needing
        # to link the SFML libraries or open an actual window.
        result = run([GCC, "-c", str(self.SRC), "-o", str(obj)])
        if result.returncode != 0 and (
            "SFML" in result.stderr or "No such file" in result.stderr
        ):
            pytest.skip("CSFML headers not available in this environment")
        assert result.returncode == 0, f"compile failed:\n{result.stderr}"
        assert obj.is_file()


# ---------------------------------------------------------------------------
# 5. CPool_Day10_2017/do_op.c -- known EMPTY stub
# ---------------------------------------------------------------------------
class TestDay10DoOpStub:
    """Per the top-level README: "the operator-dispatch logic itself is
    not present in this snapshot (the file only contains the header
    comment)". This test documents that precisely: the file compiles
    (as an empty, valid translation unit) but cannot be linked into a
    program because it defines no main() -- i.e. it is provably an
    empty stub, not just "small"."""

    SRC = ROOT / "CPool_Day10_2017" / "do_op" / "do_op.c"

    def test_source_present(self):
        assert self.SRC.is_file()

    def test_file_contains_no_executable_code(self):
        lines = [
            line.strip()
            for line in self.SRC.read_text().splitlines()
            if line.strip()
        ]
        # Every non-blank line is part of the block comment.
        assert all(
            line.startswith(("/*", "**", "*/")) for line in lines
        ), "do_op.c has grown actual code -- update this test/README note"

    @requires_gcc
    def test_compiles_as_empty_translation_unit_but_does_not_link(self, tmp_path):
        obj = tmp_path / "do_op.o"
        compile_result = run([GCC, "-c", str(self.SRC), "-o", str(obj)])
        assert compile_result.returncode == 0, (
            f"expected the empty stub to compile cleanly:\n{compile_result.stderr}"
        )

        exe = tmp_path / "do_op.exe"
        link_result = run([GCC, str(obj), "-o", str(exe)])
        assert link_result.returncode != 0, (
            "do_op.c unexpectedly linked into a full program -- it may no "
            "longer be an empty stub; update README's Day10 note"
        )
        assert "main" in link_result.stderr or "WinMain" in link_result.stderr


if __name__ == "__main__":
    sys.exit(pytest.main([__file__, "-v"]))
