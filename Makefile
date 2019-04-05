CC = gcc
CFLAGS = -W -Wall
TARGET = manager
TARGET_D = manager_debug
OBJECTS = main.o menu.o user.o
OBJECTS_D = main_d.o menu_d.o user_d.o

all : $(TARGET)

$(TARGET_D) : $(OBJECTS_D)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^ 

clean : 
	rm *.o $(TARGET) $(TARGET_D)
 

