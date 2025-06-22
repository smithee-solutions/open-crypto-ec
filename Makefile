# Make file for open-crypto-ec a/k/a open3

all:
	(cd src; make package)

clean:
	(cd src; make clean)
	(cd package; make clean)
	rm -rf build opt *.deb *.o

package:	all
	(cd package; make package)

