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

libeac-crypto-open3.a:	eac-crypto_open3.o uECC.o
	ar r libeac-crypto-open3.a uECC.o

eac-crypto_open3.o:	eac-crypto_open3.c
	${CC} ${CFLAGS} eac-crypto_open3.c

uECC.o:	micro-ecc/uECC.c
	${CC} ${CFLAGS} -o uECC.o micro-ecc/uECC.c

