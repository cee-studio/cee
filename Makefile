CC			?= gcc
OBJDIR	:= obj
LIBDIR	:= lib

SRC	:= $(wildcard http-common.c discord-*.c curl-websocket.c \
		orka-utils.c \
		settings.c ntl.c json-scanf.c json-printf.c json-string.c)

_OBJS	:= $(patsubst %.c, %.o, $(SRC))
OBJS 	:= $(addprefix $(OBJDIR)/, $(_OBJS))

LIBDISCORD_CFLAGS	:= -I./
LIBDISCORD_LDFLAGS	:=  -L./$(LIBDIR) -ldiscord -lcurl

ifeq ($(CC),stensal-c)
	LIBDISCORD_LDFLAGS += -lbearssl -static 
else
	LIBDISCORD_LDFLAGS += $(pkg-config --libs --cflags libcurl) -lcrypto -lm
endif


LIBS_CFLAGS		:= $(LIBDISCORD_CFLAGS)
LIBS_LDFLAGS	:= $(LIBDISCORD_LDFLAGS)

LIBDISCORD_SLIB	:= $(LIBDIR)/libdiscord.a

CFLAGS := -Wall -Wextra -pedantic -std=c11 -O0 -g -D_ORCA_DEBUG -D_GNU_SOURCE

ifeq ($(CC),stensal-c)
	CFLAGS += -D_DEFAULT_SOURCE
else
	CFLAGS += -fPIC -D_XOPEN_SOURCE=700
endif

PREFIX ?= /usr/local

.PHONY : all mkdir install clean purge

all : mkdir $(OBJS) $(LIBDISCORD_SLIB)

mkdir :
	mkdir -p $(OBJDIR) $(LIBDIR)

test : all test-json-scanf.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		test-json-scanf.c -o test-json-scanf.exe $(LIBS_LDFLAGS)
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		test-json-scanf-array.c -o test-json-scanf-array.exe $(LIBS_LDFLAGS)
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		test-json-string.c -o test-json-string.exe $(LIBS_LDFLAGS)

bot-echo : all bot-echo.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		bot-echo.c -o bot-echo.exe $(LIBS_LDFLAGS)
bot-pin : all bot-pin.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		bot-pin.c -o bot-pin.exe $(LIBS_LDFLAGS)
bot-ping-pong : all bot-ping-pong.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		bot-ping-pong.c -o bot-ping-pong.exe $(LIBS_LDFLAGS)
bot-log : all bot-log.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		bot-log.c -o bot-log.exe $(LIBS_LDFLAGS)

$(OBJDIR)/http-common.o : http-common.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/discord-%.o : discord-%.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/settings.o : settings.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/ntl.o : ntl.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/json-scanf.o : json-scanf.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/json-printf.o : json-printf.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/json-string.o : json-string.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/orka-utils.o : orka-utils.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) -c -o $@ $<
$(OBJDIR)/curl-websocket.o : curl-websocket.c
	$(CC) $(CFLAGS) $(LIBS_CFLAGS) \
		-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=1 -c -o $@ $<

$(LIBDISCORD_SLIB) : $(OBJS)
	$(AR) -cvq $@ $(OBJS)

install : all
	install -d $(PREFIX)/lib/
	install -m 644 $(LIBDISCORD_SLIB) $(PREFIX)/lib/
	install -d $(PREFIX)/include/
	install -m 644 libdiscord.h $(PREFIX)/include/

clean :
	rm -rf $(OBJDIR) $(LIBDIR) *.exe 

purge : clean
	rm -rf $(LIBDIR)
