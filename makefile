FILES :=                        \
    Life.c++                    \
    Life.h                      \
    Life.log                    \
    html                        \
    RunLife.in					\
    RunLife.c++                 \
    RunLife.out                 \
    TestLife.c++                \
    TestLife.out

CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

html: Doxyfile Life.h Life.c++ RunLife.c++ TestLife.c++
	doxygen Doxyfile

Life.log:
	git log > Life.log

Doxyfile:
	doxygen -g

RunLife: Life.h Life.c++ RunLife.c++
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS) Life.c++ RunLife.c++ -o RunLife

RunLife.tmp: RunLife
	./RunLife < RunLife.in > RunLife.tmp
	diff RunLife.tmp RunLife.out
	$(GPROF) ./RunLife

TestLife: Life.h Life.c++ TestLife.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Life.c++ TestLife.c++ -o TestLife $(LDFLAGS)

TestLife.tmp: TestLife
	$(VALGRIND) ./TestLife                                    >  TestLife.tmp 2>&1
	$(GCOV) -b Life.c++     | grep -A 5 "File 'Life.c++'"     >> TestLife.tmp
	$(GCOV) -b TestLife.c++ | grep -A 5 "File 'TestLife.c++'" >> TestLife.tmp
	cat TestLife.tmp

check:
    @not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunLife
	rm -f RunLife.tmp
	rm -f TestLife
	rm -f TestLife.tmp

config:
	git config -l

log: Life.log

scrub:
	make clean
	rm -f  Life.log
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunLife.tmp TestLife.tmp
