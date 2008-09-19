PACKAGE=lsb-test-olver-core
VERSION=1.5
RELEASE=1

# Derive date string for daily snapshots
ISO_DATE=$(shell date +"%Y%m%d")

# BZRTREES?=http://bzr.linux-foundation.org/lsb/devel
# BZR_MODULE=olver-core-tests

# Default target
all: rpm_package

clean:
	@rm -f *.rpm *.deb *.tgz

tarball: $(PACKAGE)-$(VERSION)-$(RELEASE).src.tgz

rpm_package: $(PACKAGE)-$(VERSION)-$(RELEASE).*.rpm

$(PACKAGE)-$(VERSION)-$(RELEASE).*.rpm:
	@sh build-olver-core-rpm.sh $(VERSION) $(RELEASE)

$(PACKAGE)-$(VERSION)-$(RELEASE).src.tgz:
	@sh ../tools/buildrpm/buildsrc.sh $(VERSION) $(RELEASE)
	@mv -f ../tools/buildrpm/$(PACKAGE)-$(VERSION)-$(RELEASE).tar.gz ./$(PACKAGE)-$(VERSION)-$(RELEASE).src.tgz

.PHONY: rpm_package