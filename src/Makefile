CC=gcc 
CFLAG=-Wall -Werror -Wextra -std=c11 
CHECK=$(shell pkg-config --cflags --libs check) 
TARGET=s21_math.a 
CCOV=-fprofile-arcs  
CCOVTEST=-fprofile-arcs -ftest-coverage
CCOVTEST_A=21_math_cov.a
TEST_A=test_s21_math.a
TEST_DIR := tests
BUILD_DIR := ./build
REPORT_DIR := report
SRC_DIRS := .
VALGRIND_LOG := val.log

# Find all the C files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.c' -or -name '*.s' | grep -v $(TEST_DIR))
TSRCS := $(shell find $(SRC_DIRS) -name '*.c' -or -name '*.s' | grep $(TEST_DIR))

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.c turns into ./build/./your_dir/hello.c.o
OBJS := $(SRCS:./%=$(BUILD_DIR)/%.o)
COV_OBJS := $(SRCS:./%.c=%.o)
GCNO := $(SRCS:./%=$(BUILD_DIR)/%.gcno)

TOBJS := $(TSRCS:./%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.c.o turns into ./build/hello.c.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
#CPPFLAGS := $(INC_FLAGS) -MMD -MP

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $@ $^
	ranlib $@

.PHONY: test
.IGNORE: test
test: $(BUILD_DIR)/$(TEST_A)
	./$^

.PHONY: build_coverage
build_coverage: $(BUILD_DIR)/$(CCOVTEST_A)

.PHONY: 
.IGNORE: gcov_report
gcov_report: test
	mkdir -p $(REPORT_DIR)
	gcov s21_*.gcda  
	gcovr -b 
	gcovr --html-details -o $(REPORT_DIR)/report.html 
	open $(REPORT_DIR)/report.html co || true

.PHONY: clean
clean:
	rm -rf $(REPORT_DIR) $(BUILD_DIR)
	rm -rf *.o *.a *.gcda *.gcno *.gcov val.log

# Build release lib within coverage
$(BUILD_DIR)/$(CCOVTEST_A): $(COV_OBJS)
	ar rc $@ $^
	ranlib $@	

# Build step for C source within coverage artifacts
%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(CCOVTEST) -c $<

# Build test ertifact
$(BUILD_DIR)/$(TEST_A): $(TOBJS) $(BUILD_DIR)/$(CCOVTEST_A)
	$(CC) -o $@ $^ $(LDFLAGS) $(CHECK) $(CCOV)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAG) -c $< -o $@

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)

# phony - говорит что файл вал не сущ это абстрактн цель
	
.PHONY: val
# $< подставляются все зависимости чтоб не писать
val: $(BUILD_DIR)/$(TEST_A)
	valgrind --tool=memcheck --leak-check=yes --log-file=$(VALGRIND_LOG) $<
