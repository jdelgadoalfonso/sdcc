include ../packages.mk

PACKAGE=autoconf
VERSION=2.68
PACKAGE_FILE=$(PACKAGE)-$(VERSION).tar.xz

PACKAGE_DIR=$(PACKAGE)-$(VERSION)

.PHONY: all
all: $(PACKAGE)-install.tag clean

download/$(PACKAGE_FILE):
	wget -P download ftp://ftp.gnu.org/gnu/$(PACKAGE)/$(PACKAGE_FILE)

$(PACKAGE)-download.tag: download/$(PACKAGE_FILE)
	touch $@

$(PACKAGE)-unpack.tag: $(PACKAGE)-download.tag
	xz -dc download/$(PACKAGE_FILE) | tar xvf -
	touch $@

$(PACKAGE)-configure.tag: $(PACKAGE)-unpack.tag
	cd $(PACKAGE_DIR) && \
	./configure --prefix=$(LOCAL_DIR)
	touch $@

$(PACKAGE)-make.tag: $(PACKAGE)-configure.tag
	$(MAKE) -C $(PACKAGE_DIR)
	touch $@

$(PACKAGE)-install.tag: $(PACKAGE)-make.tag
	$(MAKE) -C $(PACKAGE_DIR) install
	touch $@

clean:
	rm -rf $(PACKAGE_DIR) *.tag
