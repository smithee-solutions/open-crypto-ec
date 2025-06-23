# Make file for open-crypto-ec a/k/a open3

all:
	mkdir -p opt/openbadger/lib
	(cp ../SHA256/sha256.o opt/openbadger/lib)
	(cd src; make package)

clean:
	(cd src; make clean)
	(cd package; make clean)
	rm -rf build opt *.deb *.o

package:	all
	(cd package; make package)

