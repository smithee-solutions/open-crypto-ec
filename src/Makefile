LIB_OBJECTS = eac-crypto_open3-ec.o eac-crypto_open3-sha256.o \
  ECC.o \
  ../opt/openbadger/lib/sha256.o

CC=clang
CFLAGS=-c -g -I../include -I/opt/openbadger/include -Wall -Werror
LINK=clang
LDFLAGS=-g

all:	libeac-crypto-open3.a

package:	all
	mkdir -p ../opt/crypto/lib
	cp lib*a ../opt/crypto/lib

clean:
	rm -f *.o core *.a

libeac-crypto-open3.a:	${LIB_OBJECTS}
	ar r libeac-crypto-open3.a ${LIB_OBJECTS)

eac-crypto_open3.o:	eac-crypto_open3.c
	${CC} ${CFLAGS} eac-crypto_open3.c

uECC.o:	micro-ecc/uECC.c
	${CC} ${CFLAGS} -o uECC.o micro-ecc/uECC.c

