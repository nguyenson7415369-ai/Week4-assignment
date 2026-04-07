CC = gcc

# Sửa lại đường dẫn Include cho đúng thực tế folder của bạn
CFLAGS = -I../app \
         -I../common \
         -I../sys \
         -I../../libraries/ak/src \
         -DUNIT_TEST

TARGET = cli_test
SRC = test_cli.c ../common/cmd_line.c
SRC += ../common/xprintf.c


all: $(TARGET)
	@echo "--- RUNNING UNIT TEST ---"
	./$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)