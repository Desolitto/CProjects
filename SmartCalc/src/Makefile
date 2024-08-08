CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra
GLFLAGS=--coverage
FILENAME = my_smart_calc
LIBNAME = $(FILENAME).a
TARGET = Calculator_v1.0

SOURCE = $(wildcard ./qtests/my_*.c) 
SOURCETESTH = $(wildcard ./qtests/my_*.h) 

MY__C=my_*.c
MY__H=my_*.h
MY__O=my_*.o
TESTS=test_calc
SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    # Код для компиляции под Linux
	OPEN_CMD = xdg-open
    ADD_LIB =  -lcheck -lm -lsubunit
else ifeq ($(SYSTEM), Darwin)
    # Код для компиляции под macOS
	OPEN_CMD = open
	ADD_LIB =  -lcheck 
	BREW := ${HOME}/homebrew
else
    $(error Unsupported system: $(SYSTEM))
endif

all: open

$(LIBNAME): 
		$(CC) $(FLAGS) -c ./modules/my_*.c
		ar rcs $(LIBNAME) $(MY__O)
		ranlib $(LIBNAME)

# my_covered:
# 		$(CC) $(FLAGS) -c modules/my_valid.c ${SOURCE} $(GLFLAGS) ${ADD_LIB}
# 		ar rcs $(LIBNAME) $(MY__O)
# 		ranlib $(LIBNAME)

# test: clean $(LIBNAME)
# 	$(CC) ${SOURCE} -c $(FLAGS) $(GLFLAGS)
# 	$(CC) my_*.o $(LIBNAME) -o $(TESTS) ${ADD_LIB} $(FLAGS) $(GLFLAGS)
# 	./$(TESTS)

# testc: clean
# 	$(CC) $(FLAGS) -c ./modules/my_valid.c ${SOURCE} $(GLFLAGS) ${ADD_LIB}
# 	$(CC) my_*.o -o $(TESTS) ${ADD_LIB} $(FLAGS) $(GLFLAGS)
# 	./$(TESTS)

# tests: clean
# 	$(CC) $(FLAGS) -c ./modules/$(MY__C) ${SOURCE} $(GLFLAGS) ${ADD_LIB}
# 	$(CC) my_*.o -o $(TESTS) ${ADD_LIB} $(FLAGS) $(GLFLAGS)
# 	./$(TESTS)

# gcov_report: tests
# 	./$(TESTS)
# 	lcov -t $(FILENAME) -o $(FILENAME).info -c -d . --no-external    
# 	genhtml -o report $(FILENAME).info 
# 	open report/index.html



test: clean  $(LIBNAME)
	$(CC) $(FLAGS) modules/$(MY__C) ${SOURCE}  $(LIBNAME) ${ADD_LIB}  -o $(TESTS)
	./$(TESTS)

my_covered: $(LIBNAME)
		$(CC) $(FLAGS) $(GLFLAGS) modules/$(MY__C) ${SOURCE}  $(LIBNAME) ${ADD_LIB}  -o $(TESTS)
		./$(TESTS)


gcov_report: my_covered
	lcov -c -d . -o $(TESTS).info    
	genhtml  $(TESTS).info -o report
	$(OPEN_CMD) report/index.html


clean:
		rm -rf *.gcno *.html report doxygen
		rm -rf *.gcov 
		rm -rf *.gcda
		rm -rf $(TESTS) *.a
		rm -rf *.info
		rm -rf *.o
		rm -rf *.out 
		rm -rf test.dSYM a.out.dSYM test_calc.dSYM
		rm -rf ../dist ../build
		find . -name "*.qmake.stash" -exec rm -f {} \;
		find . -name "*.qmake.cache" -exec rm -f {} \;
		

test_sega: clean $(LIBNAME) 
	$(CC) $(FLAGS)  $(SOURCE)  $(LIBNAME) -o $(TESTS)  $(ADD_LIB) -fsanitize=address -g
	./$(TESTS)

leaks: test
	leaks --atExit -- ./$(TESTS)


install: uninstall
	echo "Installation of $(TARGET).app:"
	mkdir -p ../build
	cd Calc/ && qmake && make && make clean && rm -rf Makefile && mv calc.app ../../build/$(TARGET).app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	rm -rf ../build
	echo "Uninstall completed!"

open: install
	open ../build/$(TARGET).app

dvi: clean
	@doxygen Doxyfile
	open doxygen/html/index.html

dist: install
	mkdir -p ../dist
	cp -R ../build/$(TARGET).app ../dist
	cp -R . ../dist/src
	cd ../dist && tar cvzf $(TARGET).tgz *
	cd ../dist && rm -rf $(TARGET).app
	rm -rf ../dist/src
	echo "Archive creation completed successfully!"	


check:
	clang-format -style=google -i *.h ./modules/*.c ./modules/*.h ./qtests/*.c ./qtests/*.h 
	clang-format -style=google -i ./Calc/*.cpp ./Calc/*.h  

ncheck:
	clang-format -style=google -n *.h ./modules/*.c ./modules/*.h ./qtests/*.c ./qtests/*.h 
	clang-format -style=google -n ./Calc/*.cpp ./Calc/*.h  	
# *.c *.h
# clang-format -style=google -i ${SOURCE} ${SOURCETESTH} 
# cppcheck enable=all missningIncludeSystem ${SOURCE}
# cppcheck enable=all missningIncludeSystem ./modules/$(MY__C)