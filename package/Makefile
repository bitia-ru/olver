PACKAGE=lsb-test-olver-core
VERSION=4.0.90
RELEASE=3

# Derive date string for daily snapshots
ISO_DATE=$(shell date +"%Y%m%d")
PWD=$(shell pwd)

PACKAGE_NAME=$(PACKAGE)-$(VERSION)-$(RELEASE)
TARBALL=$(PACKAGE_NAME).src.tgz
SRC_DIR=$(PACKAGE)-$(VERSION)

# Handle different version generation for snapshots than for official builds
# OFFICIAL_RELEASE should be set to the tag to extract from BZR
ifdef OFFICIAL_RELEASE
	VERSION_SUFFIX=
	# EXPORT_TAG should be set to the bzr tag to use
	EXPORT_TAG=--revision=$(OFFICIAL_RELEASE)
else
	VERSION_SUFFIX=.$(ISO_DATE)
	EXPORT_TAG=
endif

# Determine whether to use rpm or rpmbuild to build the packages
ifeq ($(wildcard /usr/bin/rpmbuild),)
	RPM_BUILD_CMD=rpm
else
	RPM_BUILD_CMD=rpmbuild 
endif

# Get RPM configuration information
# NOTE THAT RPM_TMP_BUILD_DIR IS DELETED AFTER THE RPM BUILD IS COMPLETED
# The rpmrc file translates targets where there are multiple choices per
# architecture. On build, the derived RPM_BUILD_ARCH is given as the target
RCFILELIST="/usr/lib/rpm/rpmrc:./rpmrc"
RPM_TMP_BUILD_DIR=$(HOME)/tmp/rpm-build
RPM_BUILD_ARCH=$(shell rpm --rcfile ${RCFILELIST} --eval=%{_target_cpu})
RPM_BINARY_DIR=$(RPM_TMP_BUILD_DIR)/RPMS/$(RPM_BUILD_ARCH)
RPM_SRPM_DIR=$(RPM_TMP_BUILD_DIR)/SRPMS

RPM_BINARY_NAME=$(PACKAGE_NAME).$(RPM_BUILD_ARCH).rpm
RPM_SOURCE_NAME=$(PACKAGE_NAME).src.rpm

# Override this on the command line to use a different repository
BZRTREES?=http://bzr.linuxfoundation.org/lsb/devel
BZR_MODULE=olver-core-tests

# Default target
ifndef BUILD_NO_DEB
all: rpm_package deb_package
else
all: rpm_package
endif

clean:
	@rm -f *.rpm *.deb *.tgz $(PACKAGE).spec

tarball: $(TARBALL)

# Specfile generation rule
%.spec : %.spec.sed
	sed -e "s#@NAME@#`echo $(PACKAGE)`#" -e "s#@VERSION@#`echo $(VERSION)`#" -e "s#@RELEASE@#`echo $(RELEASE)`#" < $< > $@

deb_package: $(PACKAGE_NAME).*.deb

$(PACKAGE_NAME).*.deb: rpm_package
	@if [ ! `which fakeroot` ]; then \
		echo "Error: fakeroot not found. Can't build DEB."; \
	elif [ ! `which alien` ]; then \
		echo "Error: alien not found. Can't build DEB."; \
	else \
		/opt/lsb/bin/fakeroot alien -cdk $(PACKAGE_NAME).*.rpm; \
	fi

rpm_package: $(RPM_BINARY_NAME)

list_uploadable:
	@echo $(RPM_BINARY_NAME)
ifndef BUILD_NO_DEB
	@ls *.deb
endif
ifdef LIST_SOURCE_FILES
	@echo $(RPM_SOURCE_NAME) $(TARBALL)
endif

$(RPM_BINARY_NAME): $(PACKAGE).spec $(TARBALL)
	@mkdir -p $(RPM_TMP_BUILD_DIR)/BUILD
	@mkdir -p $(RPM_TMP_BUILD_DIR)/RPMS
	@mkdir -p $(RPM_TMP_BUILD_DIR)/SRPMS
ifdef SIGN_PACKAGES
	@expect -c 'set timeout -1' -c "spawn $(RPM_BUILD_CMD) --sign --rcfile $(RCFILELIST) --define=_sourcedir\ $(PWD) --define=_topdir\ $(RPM_TMP_BUILD_DIR) --define=_target_cpu\ $(RPM_BUILD_ARCH) -ba $(PACKAGE).spec" -c 'expect -ex "Enter pass phrase:"' -c 'send "\n"' -c 'expect "Executing(%clean)"' -c 'expect "exit 0"' -c 'send "\n"'
else
	@$(RPM_BUILD_CMD) --rcfile $(RCFILELIST) --define="_sourcedir $(PWD)" --define="_topdir $(RPM_TMP_BUILD_DIR)" --define="_target_cpu $(RPM_BUILD_ARCH)" -ba $(PACKAGE).spec
endif
	@mv $(RPM_BINARY_DIR)/$(RPM_BINARY_NAME) .
	@mv $(RPM_SRPM_DIR)/$(RPM_SOURCE_NAME) .
	@rm -rf $(RPM_TMP_BUILD_DIR)

$(TARBALL):
	bzr export $(EXPORT_TAG) $(SRC_DIR) $(BZRTREES)/$(BZR_MODULE)
	@tar -c $(SRC_DIR) | gzip -f9 > $(TARBALL)
	@rm -rf $(SRC_DIR)

.PHONY: rpm_package
