# Makefile that can fetch a copy of the source trees
_FETCH_EXT = $(BUILDDATE)-fetched
_FETCH_ORIGSRCTREES = $(SRCTREES:%=$(STAMPDIR)/%.$(_FETCH_EXT))
_FETCH_TREE = $(shell basename $@ .$(_FETCH_EXT))

_FETCH_DOER = mkdir -p $(STAMPDIR); \
	mkdir -p $(ORIGDIR); \
	rm -f $(STAMPDIR)/$(_FETCH_TREE).*-fetched; \
	rm -rf $(ORIGDIR)/$(_FETCH_TREE); \
	cd $(ORIGDIR); \
	if [ "$(ISRELEASE)" == "true" ]; \
	then \
	  svn $(SVNFLAGS) export https://sdcc.svn.sourceforge.net/svnroot/sdcc/tags/$(SVNTAG)/$(_FETCH_TREE) $(_FETCH_TREE) && touch $@; \
	else \
	  svn $(SVNFLAGS) export https://sdcc.svn.sourceforge.net/svnroot/sdcc/trunk/$(_FETCH_TREE) $(_FETCH_TREE) && touch $@; \
	fi

# Default rule for fetching a tree from svn
# if SVNSERVER is defined:
#   fetch by ssh-ing the SVNSERVER
# else:
#   fetch from local machine
$(STAMPDIR)/%.$(_FETCH_EXT):
	if test -z $(SVNSERVER); \
	then \
	  $(_FETCH_DOER); \
	else \
	  ssh $(SVNSERVER) "$(_FETCH_DOER)"; \
	fi

fetch-orig-trees: $(_FETCH_ORIGSRCTREES)
