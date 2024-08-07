CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra
GLFLAGS=--coverage
LIBNAME = my_string.a

SOURCE = $(wildcard ./qtests/test_*.c) 


MY_STRING_C=my_*.c
MY_STRING_H=my_*.h
MY_STRING_O=my_*.o
TESTS=test
SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    # Код для компиляции под Linux
	OPEN_CMD = xdg-open
    ADD_LIB =  -lcheck -lm -lsubunit
else ifeq ($(SYSTEM), Darwin)
    # Код для компиляции под macOS
	OPEN_CMD = open
    ADD_LIB = -lcheck
	BREW := ${HOME}/homebrew
else
    $(error Unsupported system: $(SYSTEM))
endif

PATH := $(BREW)/bin:$(PATH)

all: my_string.a  

my_string.a: 
		$(CC) $(FLAGS) -c $(MY_STRING_C)        
		ar rcs $(LIBNAME) $(MY_STRING_O)
		ranlib $(LIBNAME)

my_covered:
		$(CC) $(FLAGS) -c $(MY_STRING_C)  ${ADD_LIB} ${SOURCE} $(GLFLAGS) 
		ar rc $(LIBNAME) $(MY_STRING_O)
		ranlib $(LIBNAME)

test: clean my_covered
	$(CC) ${SOURCE} -c ${ADD_LIB} $(FLAGS) $(GLFLAGS) 
	$(CC) $(TESTS)*.o $(LIBNAME) -o $(TESTS) ${ADD_LIB} $(FLAGS) $(GLFLAGS) 

install:
	if [ $(OS) = "LINUX" ]; then \
		sudo apt-get install -y lcov; \
		sudo apt-get install -y check; \
		sudo apt-get install -y libcapture-tiny-perl; \
		sudo apt-get install -y libdatetime-perl; \
	else \
		brew install lcov; \
	fi

gcov_report: test
	./$(TESTS)
	lcov -t "my_string" -o my_string.info -c -d .
	genhtml -o report my_string.info
	open report/index.html

check:
		clang-format -style=google -i *.c *h
		clang-format -style=google -i ${SOURCE} ./qtests/test_*.h
		cppcheck enable=all missningIncludeSystem ${SOURCE}
		
clean:
		rm -rf *.gcno *.html report
		rm -rf *.gcov 
		rm -rf *.gcda
		rm -rf $(TESTS) *.a
		rm -rf *.info
		rm -rf *.o
		rm -rf *.out

rebuild: clean all
