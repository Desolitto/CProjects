CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra
GLFLAGS=--coverage
FILENAME = 3D_Viewer
LIBNAME = $(FILENAME).a
TARGET = Viewer

SOURCE = $(wildcard ./qtests/my_*.c) 
SOURCETESTH = $(wildcard ./qtests/my_*.h) 

MY__C=my_*.c
MY__H=my_*.h
MY__O=my_*.o
TESTS=test
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

all: gcov_report dvi install dist

$(LIBNAME): 
		$(CC) $(FLAGS) -c ./back/my_*.c
		ar rcs $(LIBNAME) $(MY__O)
		ranlib $(LIBNAME)

tests: clean  $(LIBNAME)
	$(CC) $(FLAGS) back/$(MY__C) ${SOURCE}  $(LIBNAME) ${ADD_LIB}  -o $(TESTS)
	./$(TESTS)

main: clean $(LIBNAME)
	$(CC) $(FLAGS) back/main.c $(LIBNAME) -o $(TESTS)
	./$(TESTS)

gcov_flag:
	$(eval FLAGS += --coverage)

gcov_report: gcov_flag tests
	lcov -c -d . -o $(TESTS).info    
	genhtml  $(TESTS).info -o report
	$(OPEN_CMD) report/index.html

clean:
		rm -rf *.gcno *.html report doxygen *.gcov *.gcda $(TESTS) *.a *.info *.o *.out 
		rm -rf test.dSYM a.out.dSYM test.dSYM
		rm -rf ../dist ../build
		find . -name "*.qmake.stash" -exec rm -f {} \;
		find . -name "*.qmake.cache" -exec rm -f {} \;
		

test_sega: clean $(LIBNAME) 
	$(CC) $(FLAGS)  $(SOURCE)  $(LIBNAME) -o $(TESTS)  $(ADD_LIB) -fsanitize=address -g
	./$(TESTS)

leaks: tests
	leaks --atExit -- ./$(TESTS)


install: uninstall
	echo "Installation of $(TARGET).app:"
	mkdir -p ../build
	cd front/Viewer/ && qmake && make && make clean && rm -rf Makefile && mv $(TARGET).app ../../../build/$(TARGET).app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	rm -rf ../build
	echo "Uninstall completed!"

# open: install
# 	open ../build/$(TARGET).app

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
	clang-format -style=google -i ./back/*.c ./back/*.h ./qtests/*.c ./qtests/*.h 
	clang-format -style=google -i ./front/Viewer/*.c* ./front/Viewer/*.h 
	cppcheck enable=all missningIncludeSystem ${SOURCE}
	cppcheck enable=all missningIncludeSystem ./back/$(MY__C)

ncheck:
	clang-format -style=google -n ./back/*.c ./back/*.h ./qtests/*.c ./qtests/*.h 
	clang-format -style=google -n ./front/Viewer/*.c* ./front/Viewer/*.h 
	cppcheck enable=all missningIncludeSystem ${SOURCE}
	cppcheck enable=all missningIncludeSystem ./back/$(MY__C)
