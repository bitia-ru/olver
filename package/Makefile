PACKAGE=lsb-test-olver-core
VERSION=1.5
RELEASE=1

# Derive date string for daily snapshots
ISO_DATE=$(shell date +"%Y%m%d")

PACKAGE_NAME=$(PACKAGE)-$(VERSION)-$(RELEASE)
TARBALL=$(PACKAGE_NAME).src.tgz
SRC_DIR=olver-core

# Handle different version generation for snapshots than for official builds
# OFFICIAL_RELEASE should be set to the tag to extract from BZR
ifdef OFFICIAL_RELEASE
	VERSION_SUFFIX=
	# EXPORT_TAG should be set to the bzr revisionspec to use
	EXPORT_TAG=--revision=$(OFFICIAL_RELEASE)
else
	VERSION_SUFFIX=.$(ISO_DATE)
	EXPORT_TAG=
endif

# Override this on the command line to use a different repository
BZRTREES?=http://bzr.linux-foundation.org/lsb/devel
BZR_MODULE=olver-core-tests

# Default target
ifndef BUILD_NO_DEB
all: rpm_package deb_package
else
all: rpm_package
endif

clean:
	@rm -f *.rpm *.deb *.tgz

tarball: $(TARBALL)

deb_package: $(PACKAGE_NAME).*.deb

$(PACKAGE_NAME).*.deb: rpm_package
	@if [ ! `which fakeroot` ]; then \
		echo "Error: fakeroot not found. Can't build DEB."; \
	elif [ ! `which alien` ]; then \
		echo "Error: alien not found. Can't build DEB."; \
	else \
		/opt/lsb/bin/fakeroot alien -cdk $(PACKAGE_NAME).*.rpm; \
	fi

rpm_package: $(PACKAGE_NAME).*.rpm

list_uploadable:
	@ls *.rpm
ifndef BUILD_NO_DEB
	@ls *.deb
endif

$(PACKAGE_NAME).*.rpm: $(SRC_DIR)
	@sh -c "$(SRC_DIR)/build_conf_tests.sh -p"
	@if [ ! -x /opt/lsb/bin/makelsbpkg ]; then \
		echo "Error: makelsbpkg not found. Can't build package."; \
		rm -rf $(SRC_DIR); \
		exit 1; \
	else \
		sh -c "$(SRC_DIR)/tools/buildrpm/buildrpm.sh $(SRC_DIR) $(VERSION) $(RELEASE)"; \
	fi
	@rm -rf $(SRC_DIR)

$(TARBALL): $(SRC_DIR)
	@tar -c $(SRC_DIR) | gzip -f9 > $(TARBALL)
	@rm -rf $(SRC_DIR)

$(SRC_DIR):
	bzr export $(EXPORT_TAG) $(SRC_DIR) $(BZRTREES)/$(BZR_MODULE)

.PHONY: rpm_package
